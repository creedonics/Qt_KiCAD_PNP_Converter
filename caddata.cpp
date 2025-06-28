#include "caddata.h"

//-------------------------------------------------------------------------------------------------//
//------------------------------*** Search for Fiducial markers ***--------------------------------//
//-------------------------------------------------------------------------------------------------//
/*
int GetFiducials(struct CadComponent *comp, struct FID *FID1_PCB, struct FID *FID2_PCB, struct FID *FID1_LAY, struct FID *FID2_LAY, int *KiCADNumberOfLines, struct ConfigFile *Conf){
    int FID1Found = 0, FID2Found = 0;
    char* Fiducial1 = "FID1";
    char* Fiducial2 = "FID2";
    struct FID FID1, FID2;
    for(int i = 0; i < *KiCADNumberOfLines; i++){ // number fo lines represents the number of components
        if(strcmp(comp[i].RefDes, Fiducial1) == 0){
            FID1.pos_x = strtod(comp[i].LocationX, NULL);
            // Inch to Mils
            //FID1.pos_x = FID1.pos_x * 1000;
            FID1.pos_x = FID1.pos_x * 39.3701;
            FID1.pos_x = round(FID1.pos_x);
            printf("FID1.x : %lf\n", FID1.pos_x);
            FID1.pos_y = strtod(comp[i].LocationY, NULL);
            // Inch to Mils
            //FID1.pos_y = FID1.pos_y * 1000;
            // Applying mirroring for KiCAD
            FID1.pos_y = FID1.pos_y * (-1);
            FID1.pos_y = FID1.pos_y * 39.3701;
            //if(Conf->Mirroir == 0) FID1_PCB->pos_y = FID1_PCB->pos_y * (-1);
            FID1.pos_y = round(FID1.pos_y);
            printf("FID1.y : %lf\n", FID1.pos_y);
            FID1_PCB->pos_x = FID1.pos_x;
            FID1_PCB->pos_y = FID1.pos_y;
            FID1_LAY->pos_x = FID1.pos_x;
            FID1_LAY->pos_y = FID1.pos_y;
            FID1Found = 1;
        }
        if(strcmp(comp[i].RefDes, Fiducial2) == 0){
            FID2.pos_x = strtod(comp[i].LocationX, NULL);
            // Inch to Mils
            //FID2.pos_x = FID2.pos_x * 1000;
            FID2.pos_x = FID2.pos_x * 39.3701;
            FID2.pos_x = round(FID2.pos_x);
            printf("FID2.x : %lf\n", FID2.pos_x);
            FID2.pos_y = strtod(comp[i].LocationY, NULL);
            // Inch to Mils
            //FID2.pos_y = FID2.pos_y * 1000;
            // Applying mirroring for KiCAD
            FID2.pos_y = FID2.pos_y * (-1);
            FID2.pos_y = FID2.pos_y * 39.3701;
            //if(Conf->Mirroir == 0) FID2_PCB->pos_y = FID2_PCB->pos_y * (-1);
            FID2.pos_y = round(FID2.pos_y);
            printf("FID2.y : %lf\n", FID2.pos_y);
            FID2_PCB->pos_x = FID2.pos_x;
            FID2_PCB->pos_y = FID2.pos_y;
            FID2_LAY->pos_x = FID2.pos_x;
            FID2_LAY->pos_y = FID2.pos_y;
            FID2Found = 1;
        }
    }
    if(FID1Found != 1) fprintf(stderr, "FID1 not Found\n");
    if(FID2Found != 1) fprintf(stderr, "FID2 not Found\n");

    FID1Found = 0;
    FID2Found = 0;
    return EXIT_SUCCESS;

}
*/
//-------------------------------------------------------------------------------------------------//


CadData::CadData(QObject *parent)
    : QObject{parent}
{}

void CadData::FindFiducials(QList<QStringList> _KiCADData)
{
    int i = 0;
    if(_KiCADData[i][0].contains("FID1")){
        qInfo() << _KiCADData[i][2];
        i++;
    }
}

void CadData::getCadConfigData(QString _ConfigData)
{
    this->ConfigData << _ConfigData;
    //qInfo() << "CAD : " << ConfigData;
}

void CadData::getKiCADData(QStringList _KiCADData)
{
    this->KiCADData.append(_KiCADData);

    this->KiCADIterator++;
    if (this->KiCADIterator + 1 == this->KiCADNumberOfLines){
        FindFiducials(this->KiCADData);
        this->KiCADIterator = 0;
    }
}

void CadData::getKiCADNumberOfLines(int _KiCADNumberOfLines)
{
    this->KiCADNumberOfLines = _KiCADNumberOfLines;
    qInfo() << " KiCAD Number of Lines : " << this->KiCADNumberOfLines;
}


