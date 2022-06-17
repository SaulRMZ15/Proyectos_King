//
//  GameViewController.swift
//  iOS3DGame
//
//  Created by Enrique Belmarez on 16/06/21.
//

import UIKit
import QuartzCore
import SceneKit

class GameViewController: UIViewController,
                          SCNSceneRendererDelegate{

    var gameView:SCNView!
    var gameScene:SCNScene!
    var cameraNode:SCNNode!
    var targetCreationTime:TimeInterval = 0
    
    @IBOutlet weak var scenekitview: SCNView!
    @IBOutlet weak var labelContador: UILabel!
    @IBOutlet weak var labelvidas: UILabel!
    
    var contador:Int = 0
    var vidas:Int = 5
    var intervalo = 0.8
    var difmedia:TimeInterval = 0
    var difalta:TimeInterval = 0
    var unavez:Bool = false
    var rangomedio:Double = 25.0
    var rangoAlto:Double = 50.0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        initView()
        initScene()
        initCamera()
        createTarget()
        labelContador.text! += ": 0"
        labelvidas.text! = "❤️❤️❤️❤️❤️"
    }
    
    func initView(){
        gameView = scenekitview
        gameView.allowsCameraControl = false
        gameView.autoenablesDefaultLighting = true
        
        gameView.delegate = self
    }
    
    func initScene () {
        gameScene = SCNScene()
        gameView.scene = gameScene
        gameView.isPlaying = true
    }
    
    func initCamera (){
        cameraNode = SCNNode()
        cameraNode.camera = SCNCamera()
        
        cameraNode.position = SCNVector3(x: 0, y: 5, z: 20)
        
        gameScene.rootNode.addChildNode(cameraNode)
    }
    
    func createTarget(){
        
        
        let dChocolate:UIImage = UIImage(named:"Chocolatedona")!
        let dAzucar:UIImage = UIImage(named:"Azucardona")!
        
        let geometry:SCNGeometry = SCNTorus(ringRadius: 0.7, pipeRadius: 0.5)
        
        
        let randomColor = arc4random_uniform(2) == 0 ?  dChocolate : dAzucar
        
        
        geometry.materials.first?.diffuse.contents = randomColor
        
        let geometryNode = SCNNode(geometry: geometry)
        
        geometryNode.physicsBody = SCNPhysicsBody(type: .dynamic, shape: nil)
        
        if randomColor == dChocolate {
            geometryNode.name = "enemy"
        }else{
            geometryNode.name = "friend"
        }
        
        gameScene.rootNode.addChildNode(geometryNode)
        let randomDirection:Float = arc4random_uniform(2) == 0 ? -1.0 : 1.0
        
        let force = SCNVector3(x: randomDirection, y: 20, z: 0)
        
        geometryNode.physicsBody?.applyForce(force, at: SCNVector3(x: 0.05, y: 0.05, z: 0.05), asImpulse: true)
    }
    
    
    func renderer(_ renderer: SCNSceneRenderer, updateAtTime time: TimeInterval) {
        if(!self.unavez){
            self.difmedia = time + self.rangomedio
            self.difalta = time + self.rangoAlto
            self.unavez = true
        }
        if time > targetCreationTime {
            createTarget()
            targetCreationTime = time + self.intervalo
        }
        if time < self.difmedia{
            self.intervalo = 0.8
            print("dentro de dificultado baja")
        }
        if time > self.difmedia && time < self.difalta {
            self.intervalo = 0.5
            print("dento de dificultad media")
        }
        if time > self.difalta {
            self.intervalo = 0.2
            print("dento de dificultad alta")
        }
        
        cleanUp()
    }
    var bonus:Int = 2
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        let touch = touches.first!
        
        let location = touch.location(in: gameView)
        
        let hitList = gameView.hitTest(location, options: nil)
        
        if let hitObject = hitList.first {
            let node = hitObject.node
            
            if node.name == "friend" {
                node.removeFromParentNode()
                self.contador += bonus
                self.labelContador.text = "Points: \(contador)"
                bonus += 1
            }else {
                node.removeFromParentNode()
                self.vidas -= 1
                if vidas == 5 {
                    self.labelvidas.text = "❤️❤️❤️❤️❤️"
                } else if vidas == 4 {
                    self.labelvidas.text = "❤️❤️❤️❤️💀"
                } else if vidas == 3 {
                    self.labelvidas.text = "❤️❤️❤️💀💀"
                } else if vidas == 2 {
                    self.labelvidas.text = "❤️❤️💀💀💀"
                } else  if vidas == 1 {
                    self.labelvidas.text = "❤️💀💀💀💀"
                }else{
                    self.labelvidas.text = "💀💀💀💀💀"
                }
                
                //self.labelvidas.text = "Vidas: \(vidas)"
                self.contador -= 5
                self.labelContador.text = "Points: \(contador)"
                bonus = 2
                if vidas == 0 {
                    let alerta = UIAlertController(title: "You lost fat", message: "You can't eat a lot of chocolate donuts\n Total Points: \(contador)", preferredStyle: .alert)
                    let reiniciar = UIAlertAction(title: "Restart", style: .default, handler: {(action) in
                        self.contador = 0
                        self.labelContador.text = "Points: \(self.contador)"
                        self.vidas = 5
                        self.labelvidas.text = "❤️❤️❤️❤️❤️"
                        self.initView()
                        self.initScene()
                        self.initCamera()
                        self.unavez = false
                        
                    })
                    let salir = UIAlertAction(title: "Exit", style: .default) { (action) in
                        self.dismiss(animated: true, completion: nil)
                    }
                    
                    alerta.addAction(reiniciar)
                    alerta.addAction(salir)
                    present(alerta, animated: true, completion: nil)
                }
            }
        }
        
    }
    
    func cleanUp(){
        for node in gameScene.rootNode.childNodes {
            if node.presentation.position.y < -2 {
                node.removeFromParentNode()
            }
        }
    }
    
    override var shouldAutorotate: Bool {
        return true
    }
    
    override var prefersStatusBarHidden: Bool {
        return true
    }
    
    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        if UIDevice.current.userInterfaceIdiom == .phone {
            return .allButUpsideDown
        } else {
            return .all
        }
    }

}
