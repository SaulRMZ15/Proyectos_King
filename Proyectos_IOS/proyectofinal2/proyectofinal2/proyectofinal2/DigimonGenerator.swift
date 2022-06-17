//
//  DigimonGenerator.swift
//  proyectofinal2
//
//  Created by Enrique Belmarez on 20/06/21.
//

import Foundation
import Combine

final class DigimonGenrator: ObservableObject {
    @Published var digimones = [Digimon]()
    @Published var leidos = false
    private var cancellable:AnyCancellable?
    
    func leerapi(){
        let enconder = JSONEncoder()
        enconder.outputFormatting = .prettyPrinted
        let url = URL(string: "https://digimon-api.vercel.app/api/digimon")


        cancellable = URLSession.shared.dataTaskPublisher(for: url!)
            .receive(on: DispatchQueue.main)
            .sink{ _ in } receiveValue: {data, _ in
                do{
                    let elementos = try JSONSerialization.jsonObject(with: data, options : .allowFragments) as? [Dictionary<String,Any>]
                    
                    for i in 0...100{
                        let digimon = Digimon(
                            name: "\(elementos![i]["name"]!)",
                            img: "\(elementos![i]["img"]!)"  ,
                            level: "\(elementos![i]["level"]!)"
                        )
                        //print(digimon)
                        self.digimones.append(digimon)
    
                    }
                    //print(elementos!)
                    print(self.digimones)
                    self.leidos = true
                }
                catch{
                    print("Error convirtiendo a json")
                }
            }
            
    }
    
}
