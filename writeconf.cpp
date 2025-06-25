#include "writeconf.h"

//-------------------------------------------------------------------------------------------------//
//-----------------------------*** Writing to MydataConfigFile ***---------------------------------//
//-------------------------------------------------------------------------------------------------//

/*int WritingMydataConfigFile(struct ConfigFile* Conf){
    // Asking for the Configuration from the User
    printf("Enter the DecalX Value :\n");
    scanf("%lf", &Conf->DecalX);
    printf("Enter the DecalY Value :\n");
    scanf("%lf", &Conf->DecalY);
    printf("Enter the Zoom Value :\n");
    scanf("%lf", &Conf->Zoom);
    printf("Enter the Angle Value :\n");
    scanf("%lf", &Conf->Angle);
    printf("Would you like to apply the mirring effect ? answer by 1 for yes or 0 for no\n");
    scanf("%d", &Conf->Mirroir);

    // Creating MydataConfigFile.ini file in writing mode
    MydataConfigFile = fopen("MydataConfigFile.ini", "w");

    if (MydataConfigFile != NULL){
        // Writing to the File
        fprintf(MydataConfigFile, "# MYDATA Configuration File\n");
        fprintf(MydataConfigFile, "[Parameters]\n");
        fprintf(MydataConfigFile, "Decalage X = %lf\n", Conf->DecalX);
        fprintf(MydataConfigFile, "Decalage Y = %lf\n", Conf->DecalY);
        fprintf(MydataConfigFile, "Zoom = %lf\n", Conf->Zoom);
        fprintf(MydataConfigFile, "Angle = %lf\n", Conf->Angle);
        fprintf(MydataConfigFile, "Mirroir = %d\n", Conf->Mirroir);

        printf("Config file created succesfully\n");
    }
    else {
        fprintf(stderr, "Unable to open the Config file!\n");
        exit(EXIT_FAILURE);
    }

    // closing the file
    fclose(MydataConfigFile);
    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------------------------------------//*/

WriteConf::WriteConf(QObject *parent)
    : QObject{parent}
{



}

void WriteConf::WritingMydataConfigFile()
{
    qInfo() << "Inside WriteConf => " << "offsetX : " << this->offsetX << " offsetY : " << this->offsetY << " scale : " << this->scale << " rot : " << this->rot << " mirror : " << this->mirror << "\n";
    QFile file("//home/creedonix/out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "# MYDATA Configuration File" << "\n";
    out << "[Parameters]" << "\n";
    out << "Decalage X = " << this->offsetX << "\n";
    out << "Decalage Y = " << this->offsetY << "\n";
    out << "Zoom = " << this->scale << "\n";
    out << "Angle = " << this->rot << "\n";
    out << "Mirroir = " << this->mirror << "\n";
}

void WriteConf::getConfigParameters(QString _offsetX, QString _offsetY, QString _scale, int _rot, bool _mirror)
{
    this->offsetX = _offsetX.toDouble();
    this->offsetY = _offsetY.toDouble();
    this->scale = _scale.toDouble();
    this->rot = _rot;
    this->mirror = _mirror;

    qInfo() << "offsetX : " << this->offsetX << " offsetY : " << this->offsetY << " scale : " << this->scale << " rot : " << this->rot << " mirror : " << this->mirror << "\n";

    WritingMydataConfigFile();
}


