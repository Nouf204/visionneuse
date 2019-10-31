#include "visionneuse.h"

Visionneuse::Visionneuse()
{
    Visionneuse::maFenetre();
}

void Visionneuse::maFenetre(){

    //**********Creation des Actions************
    //*********************************************


    //*********Action pour le premier menu*******
    QAction *actionOuvrirFichier = new QAction("Ouvrir une image...", this);
    actionOuvrirFichier->setShortcut(tr("Ctrl+O"));
    QAction *actionOuvrirDossier = new QAction("Ouvrir un dossier...", this);
    QAction *actionDeplacer=new QAction("Deplacer vers...", this);
    QAction *actionEnregistrer=new QAction("Enregistrer sous...", this);
    actionEnregistrer->setShortcut(tr("Ctrl+S"));
    QAction *actionRennomer= new QAction("Renommer...",this);
    QAction *actionQuitter = new QAction("Quitter",this);
    actionQuitter->setShortcut(tr("Ctrl+Q"));

    //*********Action pour le 2e menu*********
    QAction *actionZoomAvant= new QAction("Zoom Avant",this);
    actionZoomAvant->setShortcut(tr("Ctrl+="));
    actionZoomAvant->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/zoomAvant.png"));

    QAction *actionZoomArriere= new QAction("Zoom Arriere",this);
    actionZoomArriere->setShortcut(tr("Ctrl+-"));
    actionZoomArriere->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/zoomArriere.png"));
    QAction *actionTailleNormale=new QAction("Taille Normale",this);
    _actionDiaporama= new QAction("Diaporama",this);
    _actionDiaporama->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/play.png"));

    //******Action pour le 3e Menu********
    QAction *actionRotationDroite = new QAction("Rotation vers droite",this);
    actionRotationDroite->setShortcut(tr("Ctrl+R"));
    actionRotationDroite->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/rotationDroite.png"));

    QAction *actionRotationGauche = new QAction("Rotation vers Gauche",this);
    actionRotationGauche->setShortcut(tr("Ctrl+L"));
    actionRotationGauche->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/rotationGauche.png"));

    QAction *actionRetournementHorizontal =new QAction("Retournement Horizontal",this);
    QAction *actionRetournementVertical =new QAction("Retournement Vertical",this);

    //******Action pour le 4e Menu********
    QAction *actionAgrandirReduir = new QAction("Agrandir/Reduir",this);


    //******Action pour le toolBar********
    QAction *actionImageSuivante= new QAction("Image Suivante",this);
    actionImageSuivante->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/suivante.png"));
    actionImageSuivante->setShortcut(tr("Right"));

    QAction *actionImagePrecedente= new QAction("Image Precedente",this);
    actionImagePrecedente->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/precedente.png"));
    actionImagePrecedente->setShortcut(tr("Left"));

    QAction *actionSupprimer= new QAction("supprimer",this);
    actionSupprimer->setShortcut(tr("Del"));
    actionSupprimer->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/supprimer.png"));



    //Creation des differents menus
    //Menu fichier
    QMenu *menuFichier = menuBar()->addMenu("Fichier");
    menuFichier->addAction(actionOuvrirFichier);
    menuFichier->addAction(actionOuvrirDossier);
    menuFichier->addAction(actionDeplacer);
    menuFichier->addAction(actionEnregistrer);
    menuFichier->addAction(actionRennomer);
    menuFichier->addAction(actionQuitter);

    //Menu presentation
    QMenu *menuPresentation=menuBar()->addMenu("Presentation");
    menuPresentation->addAction(actionZoomAvant);
    menuPresentation->addAction(actionZoomArriere);
    menuPresentation->addAction(actionTailleNormale);
    menuPresentation->addAction(_actionDiaporama);

    //Menu Outils
    QMenu *menuOutils=menuBar()->addMenu("Outils");
    menuOutils->addAction(actionRotationDroite);
    menuOutils->addAction(actionRotationGauche);
    menuOutils->addAction(actionRetournementHorizontal);
    menuOutils->addAction(actionRetournementVertical);

    //Menu Fenetre
    QMenu *menuFenetre= menuBar()->addMenu("Fenetre");
    menuFenetre->addAction(actionAgrandirReduir);

    //Creation du tooBar
    QToolBar *toolBarFichier = addToolBar("bar");
    toolBarFichier->addAction(actionImagePrecedente);
    toolBarFichier->addAction(actionImageSuivante);
    toolBarFichier->addAction(actionRotationDroite);
    toolBarFichier->addAction(actionRotationGauche);
    toolBarFichier->addAction(actionZoomAvant);
    toolBarFichier->addAction(actionZoomArriere);
    toolBarFichier->addAction(actionSupprimer);
    toolBarFichier->addAction(_actionDiaporama);

    //Initialisation des differents booleens
    i=0;
    _conn=true;
    _agrandir=true;
    _horizontal=true;
    _vertical=true;


    //Les Connexions
    QObject::connect(actionOuvrirFichier, SIGNAL(triggered()), this, SLOT(ouvrirFichier()));
    QObject::connect(actionOuvrirDossier, SIGNAL(triggered()),this, SLOT(ouvrirDossier()));
    QObject::connect(actionDeplacer, SIGNAL(triggered()),this, SLOT(deplacer()));
    QObject::connect(actionImageSuivante, SIGNAL(triggered()), this, SLOT(imageSuivante()));
    QObject::connect(actionImagePrecedente, SIGNAL(triggered()), this, SLOT(imagePrecedente()));
    QObject::connect(actionRotationDroite, SIGNAL(triggered()), this, SLOT(rotationDroite()));
    QObject::connect(actionRotationGauche, SIGNAL(triggered()), this, SLOT(rotationGauche()));
    QObject::connect(actionEnregistrer, SIGNAL(triggered()), this, SLOT(enregistrerFichier()));
    QObject::connect(actionZoomAvant, SIGNAL(triggered()), this, SLOT(zoomAvant()));
    QObject::connect(actionZoomArriere, SIGNAL(triggered()), this, SLOT(zoomArriere()));
    QObject::connect(actionSupprimer, SIGNAL(triggered()), this, SLOT(supprimer()));
    QObject::connect(_actionDiaporama, SIGNAL(triggered()), this, SLOT(diaporama()));
    QObject::connect(actionRennomer, SIGNAL(triggered()), this, SLOT(renommer()));
    QObject::connect(actionAgrandirReduir, SIGNAL(triggered()), this, SLOT(agrandirReduir()));
    QObject::connect(actionRetournementHorizontal, SIGNAL(triggered()), this, SLOT(retournementHorizontal()));
    QObject::connect(actionRetournementVertical, SIGNAL(triggered()), this, SLOT(retournementVertical()));
    QObject::connect(actionTailleNormale, SIGNAL(triggered()), this, SLOT(tailleNormale()));
    QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));


    QWidget *zoneAffichage = new QWidget;
    setCentralWidget(zoneAffichage);

    //Le label qui va contenir l'image
    _label=new QLabel;
    _label->setAcceptDrops(true);

    //Le label qui va contenir le nom et la taille
    _nomImage=new QLabel;
    _nomImage->setAlignment(Qt::AlignHCenter);

    //Le scrllArea pour pouvoir afficher toute l'image
    _scrollArea = new QScrollArea();
    _scrollArea->setAlignment(Qt::AlignHCenter);
    _scrollArea->setWidget(_label);

    //La grille pour positionner les differents Objets (nom, image, scrollArea)
    _grille=new QGridLayout();
    _grille->addWidget(_scrollArea,1,1);
    _grille->addWidget(_nomImage,2,1);

    //je mets la grille dans zoneAffichage
    zoneAffichage->setLayout(_grille);

    // je redimentionne la fenetre
    resize(900,600);

}





//cette fonction me permet d'affichager l'image son nom et sa taille
void Visionneuse::afficher(){
    _image=_fileList[i];
    _label->resize(_image.height(),_image.width());
    _label->setPixmap(_image);
    _label->adjustSize();
    QDir dir1(_fileList[i]);
    QString nomImage = dir1.dirName()+" "+QString::number(_image.height())+"*"+QString::number(_image.width());
    _nomImage->setText(nomImage);
}



//ouverture d'une image
void Visionneuse::ouvrirFichier(){

    //je selectionne l'image (extension : png, gif, jpg et jpeg)
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");

    //je recupere le nom et le chemin du fichier
    QDir dir(fichier);
    dir.cdUp();
    QString cheminImage = dir.path();

    // On remplit une QStringList avec chacun des filtres désirés ici "*.jpg" et "*.png",...
    QStringList listFilter;
    listFilter << "*.jpg";
    listFilter << "*.png";
    listFilter << "*.jpeg";
    listFilter << "*.gif";

    // On déclare un QDirIterator dans lequel on indique que l'on souhaite parcourir un répertoire et ses sous-répertoires.
    // De plus, on spécifie le filtre qui nous permettra de récupérer uniquement les fichiers du type souhaité.
    QDirIterator dirIterator(cheminImage, listFilter ,QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);

    // Tant qu'on n'est pas arrivé à la fin de l'arborescence...
    while(dirIterator.hasNext())
    {
        // On va au prochain fichier correspondant à notre filtre
        _fileList << dirIterator.next();
    }

    //cette boucle me permet d'initialiser i à la position de l'image.
    int j=0;
    while(_fileList[j]!=fichier){
        j++;
    }
    i=j;

    //Affichage de l'image
    Visionneuse::afficher();

}

//ouverture d'un dossier
void Visionneuse::ouvrirDossier(){
    // On sélectionne le répertoire à partir duquel on va rechercher les fichiers jpg, png,...
    QString selectDir = QFileDialog::getExistingDirectory(this,tr("Ouvrir un répertoire"),"",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // On remplit une QStringList avec chacun des filtres désirés ici "*.mp3" et "*.avi".
    QStringList listFilter;
    listFilter << "*.jpg";
    listFilter << "*.png";
    listFilter << "*.jpeg";
    listFilter << "*.gif";

    // On déclare un QDirIterator dans lequel on indique que l'on souhaite parcourir un répertoire et ses sous-répertoires.
    // De plus, on spécifie le filtre qui nous permettra de récupérer uniquement les fichiers du type souhaité.
    QDirIterator dirIterator(selectDir, listFilter ,QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);

        // Variable qui contiendra tous les fichiers correspondant à notre recherche

        // Tant qu'on n'est pas arrivé à la fin de l'arborescence...
    while(dirIterator.hasNext())
    {
        // ...on va au prochain fichier correspondant à notre filtre
        _fileList << dirIterator.next();
    }
    i=0;

    //Affichage de l'image
    Visionneuse::afficher();
}



//deplacement d'une image
void Visionneuse::deplacer(){
    if(_fileList.isEmpty()){}
    else {
        QString emplacement = QFileDialog::getExistingDirectory(this,tr("Deplacer vers"),"",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

        //je recupere le chemin d'acces de l'image et l'extension
        QDir dir(_fileList[i]);
        dir.cdUp();
        QString cheminImage = dir.path();

        QFileInfo info(_fileList[i]);
        QString extension = info.suffix();

        dir.rename(_fileList[i], emplacement +"/"+ dir.dirName()+"."+extension);
        QFile::remove(_fileList[i]);
        Visionneuse::imageSuivante();
    }
}




//enregistrement
void Visionneuse::enregistrerFichier(){
    if(_image.isNull()){}
    else {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), _fileList[i],tr("Images (*.png *.jpg *.jpeg.*gif)"));
        _image.save(fileName);
    }
}



//image suivante
void Visionneuse::imageSuivante(){
    _vertical=true;
    _horizontal=true;

    //je verifie d'abord si la variable est bien remplie
    if(_fileList.isEmpty()){}
    else{
        //Si j'arrive à la derniere image, je retourne au debut
        if(i<_fileList.length()-1){
            i++;
            _image=_fileList[i];

            //je verifie si l'image existe vraiment, si je l'ai pas supprimé puis je l'affiche
            if(_image.height()!=0 || _image.width()!=0){

               //affichage de l'image
               Visionneuse::afficher();
            }
            else{
                Visionneuse::imageSuivante();
            }
        }
        else {
            i=0;

            //je verifie si l'image existe vraiment, si je l'ai pas supprimé puis je l'affiche
            if(_image.height()!=0 || _image.width()!=0){
                Visionneuse::afficher();
            }
            else{
                Visionneuse::imageSuivante();
            }
        }
    }
}




//image precedente
void Visionneuse::imagePrecedente(){
    _horizontal=true;
    _vertical=true;

    //je verifie si la liste n'est pas vide
    if(_fileList.isEmpty()){}
    else{

    //je verifie si on est arrivé au debut
        if(i==0){
            i=_fileList.length()-1;
            _image=_fileList[i];

            //je verifie si l'image existe vraiment si je l'ai pas supprimé
            if(_image.height()!=0 || _image.width()!=0){


                Visionneuse::afficher();
            }
            else {
                Visionneuse::imagePrecedente();
            }
        }
        else {
            i--;
            _image=_fileList[i];

            //je verifie si l'image existe vraiment si je l'ai pas supprimé avant de l'afficher
            if(_image.height()!=0 || _image.width()!=0){

                 //affichage
                Visionneuse::afficher();
            }
            else {
                Visionneuse::imagePrecedente();
            }
        }
    }
}


//rotation vers la droite
void Visionneuse::rotationDroite(){
    if(_fileList.isEmpty()){}
    else{
        _label->resize(_label->height(),_label->width());
        _image = _image.transformed(QMatrix().rotate(90));
        _label->setPixmap(QPixmap(_image));
    }
}

//rotation vers la gaucche
void Visionneuse::rotationGauche(){
    if(_fileList.isEmpty()){}
    else{
        _label->resize(_label->height(),_label->width());
        _image = _image.transformed(QMatrix().rotate(-90));
        _label->setPixmap(QPixmap(_image));
    }
}

//zoomer
void Visionneuse::zoomAvant(){

    _label->resize(_label->width()*2,_label->height()*2);
    _label->setScaledContents(true);
}




//Dezoomer
void Visionneuse::zoomArriere(){
    _label->resize(_label->width()/2,_label->height()/2);
    _label->setScaledContents(true);

}

//Suppression d'une image
void Visionneuse::supprimer(){
    if(_fileList.isEmpty()){}
    else{
        //avant de supprimer l'image definitivement je demande à l'utilisateur s'il est bien sur de lui
        int reponse = QMessageBox::question(this, "Supprimer image","Voulez-vous vraiment supprimer cette image ?",QMessageBox::Yes | QMessageBox::No);
        if(reponse == QMessageBox::Yes)
        {
            QFile::remove(_fileList[i]);
            Visionneuse::imageSuivante();
        }
    }
}

//Diaporama
void Visionneuse::diaporama(){

    //je verifie le contenue de _conn pour savoir si je dois faire la connection ou la deconnetion
    //toute les une seconde j'affiche l'image suivante et la connection je la met dans ma variable _connexion
    if(_conn==true){
        QTimer *temps = new QTimer(this);

        _connexion=temps->connect(temps, SIGNAL(timeout()),this, SLOT(imageSuivante()));
        temps->start(1000);
        _conn=false;
        _actionDiaporama->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/pause.png"));
    }
    else{
        disconnect(_connexion);
        _conn=true;
        _actionDiaporama->setIcon(QIcon("/Users/noufeine/Documents/Visionneuse/images/play.png"));
    }
}



//Renommer
void Visionneuse::renommer(){
    if(_fileList.isEmpty()){}
    else {

        //je recupere le chemin d'acces de l'image et l'extension



        QDir dir(_fileList[i]);
        dir.cdUp();
        QString cheminImage = dir.path();
        QFileInfo info(_fileList[i]);
        QString extension = info.suffix();

        bool ok = false;
        QString nouveauNom = QInputDialog::getText(this, "Renommer", "veillez entrer le nouveau nom sans l'extension", QLineEdit::Normal, QString(), &ok);

        //je verifie si il a bien appuyé sur OK avant de renommer
        if (ok && !nouveauNom.isEmpty())
        {
            QString nom= cheminImage +"/"+ nouveauNom+"."+extension;
            dir.rename(_fileList[i], nom);
            _fileList[i]=nom;
            Visionneuse::afficher();
        }
    }
}


//Agrandir ou Reduir la fenetre
void Visionneuse::agrandirReduir(){
    if(_agrandir==true){
        resize(1200,900);
        _agrandir=false;
    }
    else{
        resize(900,600);
        _agrandir=true;
    }

}

//Miroir Horizontal
void Visionneuse::retournementHorizontal(){
    if(_horizontal==true){
        _label->setPixmap(QPixmap(_image.transformed(QTransform().scale(-1, 1))));//miroir horizontal
        _horizontal=false;
    }
    else{
        _label->setPixmap(QPixmap(_image.transformed(QTransform().scale(1, 1))));//image normal
        _horizontal=true;
    }
}

//Miroir Vertical
void Visionneuse::retournementVertical(){
    if(_vertical==true){
        _label->setPixmap(QPixmap(_image.transformed(QTransform().scale(1, -1))));//image inversé vertical
        _vertical=false;
    }
    else{
        _label->setPixmap(QPixmap(_image.transformed(QTransform().scale(1, 1))));//image normal
        _vertical=true;
    }
}


//taille normale
void Visionneuse::tailleNormale(){
    if(_fileList.isEmpty()){}
    else {Visionneuse::afficher();}
}




