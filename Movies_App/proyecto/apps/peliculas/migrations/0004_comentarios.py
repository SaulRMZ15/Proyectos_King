# Generated by Django 2.1.5 on 2021-06-27 22:03

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('peliculas', '0003_auto_20210626_1853'),
    ]

    operations = [
        migrations.CreateModel(
            name='Comentarios',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('usuario', models.CharField(max_length=50)),
                ('comentario', models.CharField(max_length=250)),
                ('pelicula', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='peliculas.Pelicula')),
            ],
        ),
    ]
