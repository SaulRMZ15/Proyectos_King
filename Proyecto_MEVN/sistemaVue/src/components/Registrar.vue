<template>
   <v-card class="mx-auto my-12" shaped elevation="10">
        <v-card-title>
            <span class="headline purple--text" >Registrar</span>
        </v-card-title>            
        <v-card-text>
            <v-container grid-list-md>
                <v-layout wrap>
                    <v-flex xs12 sm6 md6>
                        <v-text-field v-model="nombre" label="Nombre" color="#8933C0"></v-text-field>
                    </v-flex>
                    <v-flex xs12 sm6 md6>
                        <v-select v-model="rol" :items="roles" label="Rol" color="primary"></v-select>
                    </v-flex>
                    <v-flex xs12 sm6 md6>
                        <v-select v-model="tipo_documento" :items="documentos" label="Tipo Documento" color="#8933C0"></v-select>
                    </v-flex>
                    <v-flex xs12 sm6 md6>
                        <v-text-field v-model="num_documento" label="Número Documento" color="#8933C0"></v-text-field>
                    </v-flex>
                    <v-flex xs12 sm12 md12>
                        <v-text-field v-model="direccion" label="Dirección" color="#8933C0"></v-text-field>
                    </v-flex>
                    <v-flex xs12 sm4 md4>
                        <v-select :items="ladas" label="País" color="#8933C0"></v-select>
                    </v-flex>
                    <v-flex xs12 sm8 md8>
                        <v-text-field v-model="telefono" label="Telefono" color="#8933C0"></v-text-field>
                    </v-flex>
                    <v-flex xs12 sm12 md12>
                        <v-text-field v-model="email" label="Correo" color="#8933C0"></v-text-field>
                    </v-flex>
                    <v-flex xs12 sm12 md12>
                        <v-text-field type="password" v-model="password" label="Contraseña" color="#8933C0"></v-text-field>
                    </v-flex>
                    <v-flex xs12 sm12 md12 v-show="valida">
                        <div class="red--text" v-for="v in validaMensaje" :key="v" v-text="v"></div>
                    </v-flex>
                </v-layout>
            </v-container>
        </v-card-text>            
    <v-card-actions>
        <v-spacer></v-spacer>
            <v-btn color="primary" @click="close()">Cancelar</v-btn>
            <v-btn color="primary" @click="guardar()">Guardar</v-btn>
    </v-card-actions>
    </v-card>
</template>
<script>
import axios from "axios";
export default {
    data(){
        return {
            _id:'',
            nombre:'',
            rol:'',
            roles:['Almacenero','Vendedor'],
            tipo_documento:'',
            documentos: ['INE', 'RFC', 'PASAPORTE', 'CEDULA', 'CURP'],
            num_documento:'',
            direccion: '',
            telefono: '',
            email:'',
            ladas:[['Albania',' +355'], ['Alemania',' +49'], ['Argentina',' +54'], ['Mexico',' +55'], ['Qatar',' +590'],['España',' +34']],
            password: '',
            valida:0,
            validaMensaje:[],
            adModal:0,
            adAccion:0,
            adNombre:'',
            adId:''
        }
    },
    methods:{
        limpiar(){
            this._id='';
            this.nombre='';
            this.num_documento='';
            this.direccion='';
            this.telefono='';
            this.email=''; 
            this.password='';
            this.valida=0;
            this.validaMensaje=[];
            this.editedIndex=-1;
        },
        validar(){
            this.valida=0;
            this.validaMensaje=[];
            if(!this.rol){
                this.validaMensaje.push('Debe seleccione un rol.');
            }
            if(this.nombre.length<1 || this.nombre.length>50){
                this.validaMensaje.push('El nombre del usuario debe tener entre 1-50 caracteres.');
            }
            if(this.num_documento.length>20){
                this.validaMensaje.push('El número de documento no debe tener más de 20 caracteres.');
            }
            if(this.direccion.length>70){
                this.validaMensaje.push('La dirección no debe tener más de 70 caracteres.');
            }
            if(!this.ladas){
                this.validaMensaje.push('Debe seleccione un país.');
            }
            if(!this.telefono.length==10){
                this.validaMensaje.push('El telefono no ceunta con los caracteres suficientes.');
            }
            if(this.email.length<1 || this.nombre.length>50){
                this.validaMensaje.push('El correo del usuario debe tener entre 1-50 caracteres.');
            }
            if(this.password.length<4 || this.nombre.length>64){
                this.validaMensaje.push('La contraseña debe tener al menos 4 caracteres.');
            }
            if (this.validaMensaje.length){
                this.valida=1;
            }
            return this.valida;
        },
        guardar(){
            let me=this;
            let header={"Token" : this.$store.state.token};
            let configuracion= {headers : header};
            if (this.validar()){
                return;
            }
            //Código para guardar
            axios.post('usuario/add',
            {
                'rol':this.rol,
                'nombre':this.nombre,
                'tipo_documento':this.tipo_documento,
                'num_documento':this.num_documento,
                'direccion':this.direccion,
                'telefono' :this.telefono,
                'email' : this.email, 
                'password' : this.password
            }
            ,configuracion)
            .then(function(response){
                me.limpiar();
                me.close();
            })
            .catch(function(error){
                console.log(error);
            });    
            },
            close () {
                 this.$router.push({name: 'login'});
            }
    }
}

</script>
