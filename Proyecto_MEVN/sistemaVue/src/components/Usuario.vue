<template>
    <v-layout align-start>
        <v-flex>
            <v-toolbar color="white">
                <v-toolbar-title class="purple--text">Usuarios</v-toolbar-title>
                <v-divider
                class="mx-2"
                inset
                vertical
                ></v-divider>
                <v-spacer></v-spacer>
                <v-text-field class="text-xs-center" v-model="search" append-icon="search" 
                label="Búsqueda" single-line hide-details></v-text-field>
                <v-spacer></v-spacer>
                <v-dialog v-model="dialog" max-width="500px">
                    <template v-slot:activator="{ on }">
                        <v-btn color="primary" dark class="mb-2" v-on="on"><v-icon>mdi-account-plus-outline</v-icon></v-btn>
                    </template>
                    <v-card>
                        <v-card-title>
                        <span class="headline">{{ formTitle }}</span>
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
                                    <div class="red--text" v-for="v in validaMensaje" :key="v" v-text="v">
                                    </div>
                                </v-flex>
                            </v-layout>
                        </v-container>
                        </v-card-text>            
                        <v-card-actions>
                        <v-spacer></v-spacer>
                        <v-btn color="primary" @click="close">Cancelar</v-btn>
                        <v-btn color="primary" @click="guardar">Guardar</v-btn>
                        </v-card-actions>
                    </v-card>
                </v-dialog>
                <v-dialog v-model="adModal" max-width="290">
                    <v-card>
                        <v-card-title class="headline" v-if="adAccion==1">
                            Activar Item
                        </v-card-title>
                        <v-card-title class="headline" v-if="adAccion==2">
                            Desactivar Item
                        </v-card-title>
                        <v-card-text>
                            Estás a punto de <span v-if="adAccion==1">activar </span>
                            <span v-if="adAccion==2">desactivar </span> el item {{adNombre}}
                        </v-card-text>
                        <v-card-actions>
                            <v-spacer></v-spacer>
                            <v-btn @click="activarDesactivarCerrar()" color="primary">
                                Cancelar
                            </v-btn>
                            <v-btn v-if="adAccion==1" @click="activar()" color="green--text">
                                Activar
                            </v-btn>
                            <v-btn v-if="adAccion==2" @click="desactivar()" color="orange--text">
                                Desactivar
                            </v-btn>
                        </v-card-actions>
                    </v-card>
                </v-dialog>
            </v-toolbar>
            <v-data-table :headers="headers" :items="usuarios" :search="search"  class="elevation-1">
                <template v-slot:[`item.opciones`]="{ item }">
                    <v-icon small class="mr-2" @click="editedItem(item)" color="primary">mdi-square-edit-outline</v-icon>
                    <template v-if="item.estado">
                        <v-icon small @click="activarDesactivarMostrar(2,item)" color="red">mdi-eye-off-outline</v-icon>
                    </template>
                    <template v-else>
                        <v-icon small @click="activarDesactivarMostrar(1,item)" color="green">mdi-eye-outline</v-icon>
                    </template>
                </template>
                <template v-slot: items="props">
                    <td>{{props.item.nombre}}</td>
                    <td>{{props.item.rol}}</td>
                    <td>{{props.item.tipo_documento}}</td>
                    <td>{{props.item.num_documento}}</td>
                    <td>{{props.item.direccion}}</td>
                    <td>{{props.item.telefono}}</td>
                    <td>{{props.item.email}}</td>
                </template>
                <template v-slot:[`item.estado`]="{ item }">
                        <div v-if="item.estado">
                            <span class="blue--text">Activo</span>
                        </div>
                        <div v-else>
                            <span class="red--text">Inactivo</span>
                        </div>
                </template>
                <template v-slot:no-data>
                    <v-btn color="purple--text" @click="listar()">Resetear</v-btn>
                </template>
            </v-data-table>
        </v-flex>
    </v-layout>
</template>
<script>
    import axios from 'axios'
    export default {
        data(){
            return{
                dialog: false,
                search:'',
                usuarios:[],
                headers: [
                    { text: 'Opciones', value: 'opciones', sortable: false },
                    { text: 'Nombre', value: 'nombre', sortable: true },
                    { text: 'Rol', value: 'rol', sortable: true },
                    { text: 'Tipo Documento', value: 'tipo_documento', sortable: true },
                    { text: 'Número Documento', value: 'num_documento', sortable: false },
                    { text: 'Dirección', value: 'direccion', sortable: false },
                    { text: 'Telefono', value: 'telefono', sortable: false },
                    { text: 'Correo', value: 'email', sortable: false },
                    // { text: 'Password', value: 'password', sortable: false },
                    { text: 'Estado', value: 'estado', sortable: false },
                ],
                editedIndex: -1,
                _id:'',
                nombre:'',
                rol:'',
                roles:['Administrador', 'Almacenero','Vendedor'],
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
                adId:'',
            }
        },
        computed: {
            formTitle () {
            return this.editedIndex === -1 ? 'Nuevo registro' : 'Editar registro'
            }
        },
        watch: {
            dialog (val) {
            val || this.close()
            }
        },
        created () {
            this.listar()
        },
        methods: {
            listar(){
                let me=this;
                let header={"Token" : this.$store.state.token};
                let configuracion= {headers : header};            
                axios.get('usuario/list',configuracion).then(function (response){
                    me.usuarios=response.data;
                }).catch(function(error){
                    console.log(error);
                });

            },
            limpiar(){
                this._id='';
                this.nombre='';
                //this.rol='';
                //this.nombre='';
                //this.tipo_documento='';
                this.num_documento='';
                this.direccion='';
                //this.ladas='';
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
                if (this.editedIndex >-1){
                    //Código para editar
                    axios.put('usuario/update',
                    {
                        '_id':this._id,
                        'rol':this.rol,
                        'nombre':this.nombre,
                        'tipo_documento':this.tipo_documento,
                        'num_documento':this.num_documento,
                        'direccion':this.direccion,
                        'telefono': this.telefono,
                        'email':this.email,
                        'password':this.password
                    },configuracion)
                    .then(function(response){
                        me.limpiar();
                        me.close();
                        me.listar();
                    })
                    .catch(function(error){
                        console.log(error);
                    });
                }else{
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
                        me.listar();
                    })
                    .catch(function(error){
                        console.log(error);
                    });
                }
            },
            editedItem (item) {
                this._id=item._id;
                this.rol=item.rol;
                this.nombre=item.nombre;
                this.tipo_documento=item.tipo_documento;
                this.num_documento=item.num_documento;
                this.direccion=item.direccion;
                this.telefono=item.telefono;
                this.email=item.email;
                this.password=item.password;
                this.dialog = true;
                this.editedIndex=1;
            },
            activarDesactivarMostrar(accion,item){
                this.adModal=1;
                this.adNombre=item.nombre;
                this.adId=item._id;
                if (accion==1){
                    this.adAccion=1;
                } else if(accion==2){
                    this.adAccion=2;
                } else{
                    this.adModal=0;
                }
            },
            activarDesactivarCerrar(){
                this.adModal=0;
            },
            activar(){
                let me=this;
                let header={"Token" : this.$store.state.token};
                let configuracion= {headers : header};
                axios.put('usuario/activate',{'_id':this.adId},configuracion)
                    .then(function(response){
                        me.adModal=0;
                        me.adAccion=0;
                        me.adNombre='';
                        me.adId='';
                        me.listar();
                    })
                    .catch(function(error){
                        console.log(error);
                    });
            },
            desactivar(){
                let me=this;
                let header={"Token" : this.$store.state.token};
                let configuracion= {headers : header};
                axios.put('usuario/deactivate',{'_id':this.adId},configuracion)
                    .then(function(response){
                        me.adModal=0;
                        me.adAccion=0;
                        me.adNombre='';
                        me.adId='';
                        me.listar();
                    })
                    .catch(function(error){
                        console.log(error);
                    });
            },
            close () {
                this.dialog = false;
            }
        }
    }
</script>