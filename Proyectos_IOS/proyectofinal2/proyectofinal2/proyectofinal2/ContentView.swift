//
//  ContentView.swift
//  proyectofinal2
//
//  Created by Enrique Belmarez on 19/06/21.
//

import SwiftUI





struct ContentView: View {
    @StateObject private var digimonGenerator = DigimonGenrator()
    var body: some View {
        
        VStack{
                if digimonGenerator.leidos
                {
                    NavigationView{
                        List(digimonGenerator.digimones){
                            Digimon in
                            //NavigationLink(destination: EmptyView()){
                            NavigationLink(destination: detailViewDigimon(digimon: Digimon)){
                                VStack{
                                    imgDigimon(digimon: Digimon)
                                        .frame(width: 120, height: 120, alignment: /*@START_MENU_TOKEN@*/.center/*@END_MENU_TOKEN@*/)
                                        .overlay(Circle() .stroke(Color.blue, lineWidth: 3))
                                        .padding()
                                    Text(Digimon.name)
                                        .font(.headline)
                                        .foregroundColor(.blue)
                                }.padding(10)
                                .position(x: UIScreen.main.bounds.width/2, y: 90)
                               
                            }
                            //.scaledToFit()
                        }
                        .foregroundColor(.white)
                        .navigationBarTitle("🐙🐙 DIGIMONES 🦖🦖", displayMode: .inline)
                    }.foregroundColor(/*@START_MENU_TOKEN@*/.blue/*@END_MENU_TOKEN@*/)//.frame(width: 400, height: 700, alignment: .center)
                    
                    
                    /*let name = digimonGenerator.digimones[0].name
                    let img = digimonGenerator.digimones[0].img
                    let level = digimonGenerator.digimones[0].level
                    Text(name)
                        .font(.largeTitle)
                    AsyncImage(url: URL(string: img)!,
                                   placeholder: { Text("Loading ...") },
                                   image: { Image(uiImage: $0).resizable() }).aspectRatio(contentMode: .fit)
                Text(level)*/
                }
        }.onAppear{digimonGenerator.leerapi()}
        
    }
    
    
}


struct imgDigimon: View{
    let digimon: Digimon
    var body: some View {
        ZStack{
            AsyncImage(url: URL(string: digimon.img)!,
                           placeholder: { Text("Loading ...") },
                           image: { Image(uiImage: $0).resizable() }).aspectRatio(contentMode: .fit)
                
        }
    }
}

struct detailViewDigimon:View {
    let digimon: Digimon
    var body: some View{
        VStack(){
                imgDigimon(digimon: digimon)
                    .overlay(RoundedRectangle(cornerRadius: 25.0 , style: .circular) .stroke(Color.blue, lineWidth: 3))
            Text("Identificador :")
            Text("\(digimon.id)")
            Spacer()
            Text("Nombre :")
                Text(digimon.name)
                    .foregroundColor(.orange)
                    .font(.largeTitle)
                    .bold()
                Spacer()
            Text("Nivel :")
            Text(digimon.level)
                .bold()
                .padding(.top)
            Spacer()
        }
        .padding()
        .navigationBarTitle(Text(digimon.name), displayMode: .inline)
        
    }
}



struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
