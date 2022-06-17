import Vue from 'vue';
import Vuetify from 'vuetify/lib/framework';
import es from 'vuetify/lib/locale/es';
import '@mdi/font/css/materialdesignicons.css';

Vue.use(Vuetify);
export default new Vuetify({
  theme: {
      options: {
        customProperties: true,
      },
    themes: {
      light: {
        primary: '#8933C0',
        secondary: '#424242',
        colorP: '#00ACC1',
        accent: '#82B1FF',
        error: '#FF5252',
        info: '#2196F3',
        success: '#4CAF50',
        warning: '#FFC107'
      },
    },
  },
    lang: {
      locales: { es },
      current: 'es',
    },
  icons: {
    iconfont: 'md',
    iconfont: 'mdiSvg',
  },
});
