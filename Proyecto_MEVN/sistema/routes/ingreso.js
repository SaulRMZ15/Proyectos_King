import routerx from 'express-promise-router';
import ingresoController from '../controllers/IngresoController';
import auth from '../middlewares/auth'

const router=routerx();

router.post('/add',auth.verifyAlmacenero, ingresoController.add);
router.get('/query',auth.verifyAlmacenero, ingresoController.query);
router.get('/list',auth.verifyAlmacenero, ingresoController.list);
router.put('/activate',auth.verifyAlmacenero, ingresoController.activate);
router.put('/deactivate',auth.verifyAlmacenero, ingresoController.deactivate);
// router.get('/graficos12Meses',auth.verifyUsuario, ingresoController.graficos12Meses);
router.get('/consultaFechas',auth.verifyUsuario, ingresoController.consultaFechas);

export default router;