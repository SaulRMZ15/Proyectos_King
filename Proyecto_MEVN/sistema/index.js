//const express=require('express');
import express from 'express';
//const morgan=require('morgan');
import morgan from 'morgan';
//const cors=require('cors');
import cors from 'cors';

import path from 'path';

import mongoose from 'mongoose';

import router from './routes';

//conexion con la bd MongoDB
mongoose.Promise=global.Promise;
const dbUrl = 'mongodb://localhost:27017/dbsistema';
mongoose.connect(dbUrl, {useCreateIndex:true, useNewUrlParser:true})
.then(mongoose => console.log('Conectado a la BD en el puerto 27017'))
.catch(err => console.log(err));

const app=express();
app.use(morgan('dev'));
app.use(cors());

app.use(express.json());
app.use(express.urlencoded({extended:true}));
app.use(express.static(path.join(__dirname , 'public')));

app.use('/api',router);

app.set('port', process.env.PORT || 3000);
//Prueba del middlewares
//app.get('/hola', function (req, res) {
    //res.send('Hello World!');
//});

app.listen(app.get('port'),()=>{
    console.log('Server on port '+ app.get('port'));
});