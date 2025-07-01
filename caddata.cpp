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


/*
//-------------------------------------------------------------------------------------------------//
//---------------------------------*** Apply configurations ***------------------------------------//
//-------------------------------------------------------------------------------------------------//

int ApplyConfigurations(struct CadComponent *comp, struct ConfigFile *Conf, struct FID *FID1_PCB, struct FID *FID2_PCB, struct FID *FID1_LAY, struct FID *FID2_LAY, int *KiCADNumberOfLines){

    int Rotation_buf = 0;

    struct comp_buf {
        double PosX;
        double PosY;
        double Rot;
    }comp_buf[*KiCADNumberOfLines];

    //--------------------------------*** Apply Rotation on FID_LAY ***------------------------------------//
    switch(((int) Conf->Angle)){
    case 90: // (x,y) => (-y,x)
        // FID1
        Rotation_buf = FID1_LAY->pos_x;
        FID1_LAY->pos_x = FID1_LAY->pos_y;
        FID1_LAY->pos_y = Rotation_buf;
        FID1_LAY->pos_x = FID1_LAY->pos_x * (-1);

        // FID2
        Rotation_buf = FID2_LAY->pos_x;
        FID2_LAY->pos_x = FID2_LAY->pos_y;
        FID2_LAY->pos_y = Rotation_buf;
        FID2_LAY->pos_x = FID2_LAY->pos_x * (-1);

        break;
    case 180: // (x,y) => (-x,-y)
        // FID1
        FID1_LAY->pos_x = FID1_LAY->pos_x * (-1);
        FID1_LAY->pos_y = FID1_LAY->pos_y * (-1);

        // FID2
        FID2_LAY->pos_x = FID2_LAY->pos_x * (-1);
        FID2_LAY->pos_y = FID2_LAY->pos_y * (-1);

        break;
    case 270: // (x,y) => (y,-x)
        // FID1
        Rotation_buf = FID1_LAY->pos_x;
        FID1_LAY->pos_x = FID1_LAY->pos_y;
        FID1_LAY->pos_y = Rotation_buf;
        FID1_LAY->pos_y = FID1_LAY->pos_y * (-1);

        // FID2
        Rotation_buf = FID2_LAY->pos_x;
        FID2_LAY->pos_x = FID2_LAY->pos_y;
        FID2_LAY->pos_y = Rotation_buf;
        FID2_LAY->pos_y = FID2_LAY->pos_y * (-1);

        break;
    default :
        break;

    }

    //-------------------------------------------------------------------------------------------------//

    //-------------------------*** Apply shifting and zoom on FID ***----------------------------------//
    // FID1
    FID1_LAY->pos_x = (FID1_LAY->pos_x + Conf->DecalX) * Conf->Zoom;
    FID1_LAY->pos_y = (FID1_LAY->pos_y + Conf->DecalY) * Conf->Zoom;

    // FID2
    FID2_LAY->pos_x = (FID2_LAY->pos_x + Conf->DecalX) * Conf->Zoom;
    FID2_LAY->pos_y = (FID2_LAY->pos_y + Conf->DecalY) * Conf->Zoom;
    //-------------------------------------------------------------------------------------------------//

    for(int i = 0; i < *KiCADNumberOfLines; i++){

        //-----------------*** Converting strings to double to apply configurations ***--------------------//
        comp_buf[i].PosX = strtod(comp[i].LocationX, NULL);
        comp_buf[i].PosY = strtod(comp[i].LocationY, NULL);
        comp_buf[i].Rot = strtod(comp[i].Rotation, NULL);
        //-------------------------------------------------------------------------------------------------//

        //-----------------------*** Converting the values from Inch to Mils ***---------------------------//
        //comp_buf[i].PosX = comp_buf[i].PosX * 1000;
        //comp_buf[i].PosY = comp_buf[i].PosY * 1000;
        //-------------------------------------------------------------------------------------------------//

        //-----------------------*** Converting the values from mm to mils ***-----------------------------//
        comp_buf[i].PosX = comp_buf[i].PosX * 39.3701;
        comp_buf[i].PosY = comp_buf[i].PosY * 39.3701;
        //-------------------------------------------------------------------------------------------------//

        //--------------------*** Adapting the KiCAD Values to match the PNP ones ***----------------------//
        comp_buf[i].PosX = comp_buf[i].PosX + 125;
        comp_buf[i].PosY = comp_buf[i].PosY + 7725;
        //comp_buf[i].PosY = comp_buf[i].PosY * (-1);
        //-------------------------------------------------------------------------------------------------//

        //------------------------*** Adjusting the rotation of components ***-----------------------------//
        if(comp_buf[i].Rot < 0) comp_buf[i].Rot = comp_buf[i].Rot + 360;
        //-------------------------------------------------------------------------------------------------//


        //-----------------------*** Apply shifting and zoom on components ***-----------------------------//
        comp_buf[i].PosX = (comp_buf[i].PosX - FID1_PCB->pos_x) * Conf->Zoom;
        comp_buf[i].PosY = (comp_buf[i].PosY - FID1_PCB->pos_y) * Conf->Zoom;
        //-------------------------------------------------------------------------------------------------//

        //---------------------------*** Apply mirroring on components ***---------------------------------//
        if(Conf->Mirroir == 1) comp_buf[i].PosY = comp_buf[i].PosY * (-1);
        //-------------------------------------------------------------------------------------------------//

        //---------------------------*** Apply Rotation on Components ***----------------------------------//
        comp_buf[i].Rot = comp_buf[i].Rot - 90; // since all components are loaded in 90 deg to the machine

        switch(((int) Conf->Angle)){
        case 90: // (x,y) => (-y,x)
            Rotation_buf = comp_buf[i].PosX;
            comp_buf[i].PosX = comp_buf[i].PosY;
            comp_buf[i].PosY = Rotation_buf;
            comp_buf[i].PosX = comp_buf[i].PosX * (-1);

            break;
        case 180: // (x,y) => (-x,-y)
            comp_buf[i].PosX = comp_buf[i].PosX * (-1);
            comp_buf[i].PosY = comp_buf[i].PosY * (-1);

            break;
        case 270: // (x,y) => (y,-x)
            Rotation_buf = comp_buf[i].PosX;
            comp_buf[i].PosX = comp_buf[i].PosY;
            comp_buf[i].PosY = Rotation_buf;
            comp_buf[i].PosY = comp_buf[i].PosY * (-1);

            break;
        default :
            break;

        }
        //-------------------------------------------------------------------------------------------------//

        //---------------------*** Adapting the component values to the MYDATA ***-------------------------//
        comp_buf[i].PosX = round(comp_buf[i].PosX);
        comp_buf[i].PosY = round(comp_buf[i].PosY);
        comp_buf[i].Rot = comp_buf[i].Rot * 1000;
        //-------------------------------------------------------------------------------------------------//

        //---------------*** Converting the values to string for writing in the file ***-------------------//
        snprintf(comp[i].LocationX, 2*sizeof(comp_buf[i].PosX), "%d", (int) comp_buf[i].PosX);
        //printf("LocationX : %s ; PosX : %lf\n", comp[i].LocationX, comp_buf[i].PosX);
        snprintf(comp[i].LocationY, 2*sizeof(comp_buf[i].PosY), "%d", (int) comp_buf[i].PosY);
        //printf("LocationY : %s ; PosY : %lf\n", comp[i].LocationY, comp_buf[i].PosY);
        snprintf(comp[i].Rotation, 2*sizeof(comp_buf[i].Rot), "%d", (int) comp_buf[i].Rot);
        //printf("Rotation : %s ; Rot : %lf\n", comp[i].Rotation, comp_buf[i].Rot);
        //-------------------------------------------------------------------------------------------------//

    }


    return EXIT_SUCCESS;

}

//-------------------------------------------------------------------------------------------------//
*/

CadData::CadData(QObject *parent)
    : QObject{parent}
{

}

void CadData::FindFiducials(QStringList _KiCADData)
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
    this->LibData = _LibData;
    this->LibFileNumberOfLines = _LibFileNumberOfLines;
    for (int i = 0; i < this->KiCADNumberOfComponents; i++) {
        if( !( KiCADData[i][Ref].contains("FID1") || KiCADData[i][Ref].contains("FID2") ) ){
            for (int j = 0; j < this->LibFileNumberOfLines; j++) {
                if( (this->LibData[j][typeboitierCAO] == this->KiCADData[i][Package] ) && (this->LibData[j][valeurCAO] == this->KiCADData[i][Val]) ){
                    this->UsedLibData.append(this->LibData[j]);
                    //qInfo() << this->LibData[j][typeboitierCAO] << " " << this->LibData[j][valeurCAO];
                    //qInfo() << this->UsedLibData;
                }
            }
        }
    }
}

void CadData::getKiCADData(QList<QStringList> _KiCADData, int _KiCADNumberOfComponents)
{
    this->KiCADData = _KiCADData;
    this->KiCADNumberOfComponents = _KiCADNumberOfComponents;
    //qInfo() << this->KiCADData.size();
    for (int i = 0; i < _KiCADNumberOfComponents; ++i) {
        FindFiducials(_KiCADData[i]);
    }
}

void CadData::getKiCADNumberOfLines(int _KiCADNumberOfLines)
{
    this->KiCADNumberOfLines = _KiCADNumberOfLines;
    qInfo() << " KiCAD Number of Lines : " << this->KiCADNumberOfLines;
}


