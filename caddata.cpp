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
{

}

void CadData::FindFiducials(QStringList _KiCADData) // need to fix this
{
    if(_KiCADData[0].contains("FID1")){
        FID1_X = _KiCADData[PosX].toDouble();
        FID1_Y = _KiCADData[PosY].toDouble();
        //qInfo() << "FID1 => " <<"PosX : " << FID1_X << "PosY : " << FID1_Y;

    }
    if(_KiCADData[0].contains("FID2")){
        FID2_X = _KiCADData[PosX].toDouble();
        FID2_Y = _KiCADData[PosY].toDouble();
        //qInfo() << "FID2 => " <<"PosX : " << FID2_X << "PosY : " << FID2_Y;
    }
}

void CadData::getCadConfigData(QString _ConfigData)
{
    this->ConfigData << _ConfigData;
    //qInfo() << "CAD : " << ConfigData;
}

void CadData::getLibData(QList<QStringList> _LibData, int _LibFileNumberOfLines)
{
    //qInfo() << _LibData;
    //if((strcmp(comp[i].Type, TempLibFileVal[(j-1)*7]) == 0) && (strcmp(comp[i].Value, TempLibFileVal[1+(j-1)*7]) == 0))
    //if((this->KiCADData[KiCADIterator][Ref] == _LibData[typeboitierCAO]) && (this->KiCADData[KiCADIterator][Val] == _LibData[valeurCAO])){
    //QListIterator<QStringList> LibDataIterator(this->LibData);
    //int i=0;
    this->LibData = _LibData;
    this->LibFileNumberOfLines = _LibFileNumberOfLines;
    qInfo() << LibData;
    qInfo() << LibFileNumberOfLines;

    /*
    while(this->KiCADIterator != this->KiCADData.size()){
        if((_LibData[typeboitierCAO].contains(this->KiCADData[KiCADIterator][Package])) && (_LibData[valeurCAO].contains(this->KiCADData[KiCADIterator][Val]))){
            if(this->LibData.size() == 0){
                this->LibData.append(_LibData);
            }
            else if( !( (this->LibData[i][typeboitierCAO].contains(this->KiCADData[KiCADIterator][Package])) && (this->LibData[i][valeurCAO].contains(this->KiCADData[KiCADIterator][Val])) ) ){
                this->LibData.append(_LibData);
                qInfo() << this->LibData[i];
                i++;
            }
        }
        this->KiCADIterator++;
    }
    this->KiCADIterator = 0;*/
    //this->KiCADIterator = this->KiCADIterator == this->KiCADData.size() ? 0 : this->KiCADIterator;
}

void CadData::getKiCADData(QList<QStringList> _KiCADData, int KiCADNumberOfComponents)
{

    this->KiCADData = _KiCADData;
    //qInfo() << this->KiCADData.size();
    //FindFiducials(_KiCADData.); need to fix this

}

void CadData::getKiCADNumberOfLines(int _KiCADNumberOfLines)
{
    this->KiCADNumberOfLines = _KiCADNumberOfLines;
    qInfo() << " KiCAD Number of Lines : " << this->KiCADNumberOfLines;
}


