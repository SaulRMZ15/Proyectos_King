import routerx from 'express-promise-router';
import ventaController from '../controllers/VentaController';
import auth from '../middlewares/auth'

const router=routerx();

router.post('/add',auth.verifyVendedor, ventaController.add);
router.get('/query',auth.verifyVendedor, ventaController.query);
router.get('/list',auth.verifyVendedor, ventaController.list);
router.put('/activate',auth.verifyVendedor, ventaController.activate);
router.put('/deactivate',auth.verifyVendedor, ventaController.deactivate);
// router.get('/grafico12Meses',auth.verifyUsuario, ventaController.graficos12Meses);
router.get('/consultaFechas',auth.verifyUsuario, ventaController.consultaFechas);

export default router;