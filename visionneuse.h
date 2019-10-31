#ifndef VISIONNEUSE_H
#define VISIONNEUSE_H

#include <QMainWindow>
#include<QWidget>
#include<QFileDialog>
#include<QDirIterator>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QMessageBox>
#include<QLabel>
#include<QFontComboBox>
#include<QToolBar>
#include<QScrollArea>
#include<QGuiApplication>
#include<QGridLayout>
#include<QPushButton>
#include<QTimer>
#include <QTransform>
#include<QInputDialog>
#include<QColor>

class Visionneuse : public QMainWindow
{
    Q_OBJECT

public:
     Visionneuse();
     void afficher();
     void maFenetre();

public slots:

    void ouvrirFichier();
    void ouvrirDossier();
    void deplacer();
    void enregistrerFichier();
    void imageSuivante();
    void imagePrecedente();
    void rotationDroite();
    void rotationGauche();
    void zoomAvant();
    void zoomArriere();
    void supprimer();
    void diaporama();
    void renommer();
    void agrandirReduir();
    void retournementHorizontal();
    void retournementVertical();
    void tailleNormale();


private:
    QStringList _fileList;
    QLabel *_label;
    QLabel *_nomImage;
    QGridLayout *_grille;
    QPixmap _image;
    QScrollArea *_scrollArea;
    QAction *_actionDiaporama;

    QMetaObject::Connection _connexion;
    int i;
    bool _conn;
    bool _agrandir;
    bool _horizontal;
    bool _vertical;
};

#endif // VISIONNEUSE_H
