//
//  ViewController.swift
//  proyectofinal1
//
//  Created by Enrique Belmarez on 17/06/21.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var startBtn: UIButton!
    
    @IBOutlet weak var howtoPlayBtn: UIButton!
    
    @IBOutlet weak var aboutBtn: UIButton!
    
    @IBOutlet weak var exitBtn: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        startBtn.layer.cornerRadius = 10
        howtoPlayBtn.layer.cornerRadius = 10
        aboutBtn.layer.cornerRadius = 10
        exitBtn.layer.cornerRadius = 10
    }

    @IBAction func btnSalir(_ sender: Any) {
        exit(0)
    }
    
    @IBAction func btnAbout(_ sender: Any) {
        let alerta = UIAlertController(title: "About", message: "This apliccation was make by Kevin Saul Ramirez Romero NC:17131622 and Enrique Belmarez Meraz NC:17130765 for the IOS Developer Class", preferredStyle: .alert)
        let OK = UIAlertAction(title: "OKEY 👨🏻‍🦲", style: .default, handler: {(action) in
            
            
        })
        
        alerta.addAction(OK)
        present(alerta, animated: true, completion: nil)
        
    }
    
    
}

