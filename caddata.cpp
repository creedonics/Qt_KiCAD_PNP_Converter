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
            FID1_X = strtod(comp[i].LocationX, NULL);
            // Inch to Mils
            //FID1_X = FID1_X * 1000;
            FID1_X = FID1_X * 39.3701;
            FID1_X = round(FID1_X);
            printf("FID1.x : %lf\n", FID1_X);
            FID1_Y = strtod(comp[i].LocationY, NULL);
            // Inch to Mils
            //FID1_Y = FID1_Y * 1000;
            // Applying mirroring for KiCAD
            FID1_Y = FID1_Y * (-1);
            FID1_Y = FID1_Y * 39.3701;
            //if(Conf->Mirroir == 0) FID1_PCB_Y = FID1_PCB_Y * (-1);
            FID1_Y = round(FID1_Y);
            printf("FID1.y : %lf\n", FID1_Y);
            FID1_PCB_X = FID1_X;
            FID1_PCB_Y = FID1_Y;
            FID1_LAY_X = FID1_X;
            FID1_LAY_Y = FID1_Y;
            FID1Found = 1;
        }
        if(strcmp(comp[i].RefDes, Fiducial2) == 0){
            FID2_X = strtod(comp[i].LocationX, NULL);
            // Inch to Mils
            //FID2_X = FID2_X * 1000;
            FID2_X = FID2_X * 39.3701;
            FID2_X = round(FID2_X);
            printf("FID2.x : %lf\n", FID2_X);
            FID2_Y = strtod(comp[i].LocationY, NULL);
            // Inch to Mils
            //FID2_Y = FID2_Y * 1000;
            // Applying mirroring for KiCAD
            FID2_Y = FID2_Y * (-1);
            FID2_Y = FID2_Y * 39.3701;
            //if(Conf->Mirroir == 0) FID2_PCB_Y = FID2_PCB_Y * (-1);
            FID2_Y = round(FID2_Y);
            printf("FID2.y : %lf\n", FID2_Y);
            FID2_PCB_X = FID2_X;
            FID2_PCB_Y = FID2_Y;
            FID2_LAY_X = FID2_X;
            FID2_LAY_Y = FID2_Y;
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
        Rotation_buf = FID1_LAY_X;
        FID1_LAY_X = FID1_LAY_Y;
        FID1_LAY_Y = Rotation_buf;
        FID1_LAY_X = FID1_LAY_X * (-1);

        // FID2
        Rotation_buf = FID2_LAY_X;
        FID2_LAY_X = FID2_LAY_Y;
        FID2_LAY_Y = Rotation_buf;
        FID2_LAY_X = FID2_LAY_X * (-1);

        break;
    case 180: // (x,y) => (-x,-y)
        // FID1
        FID1_LAY_X = FID1_LAY_X * (-1);
        FID1_LAY_Y = FID1_LAY_Y * (-1);

        // FID2
        FID2_LAY_X = FID2_LAY_X * (-1);
        FID2_LAY_Y = FID2_LAY_Y * (-1);

        break;
    case 270: // (x,y) => (y,-x)
        // FID1
        Rotation_buf = FID1_LAY_X;
        FID1_LAY_X = FID1_LAY_Y;
        FID1_LAY_Y = Rotation_buf;
        FID1_LAY_Y = FID1_LAY_Y * (-1);

        // FID2
        Rotation_buf = FID2_LAY_X;
        FID2_LAY_X = FID2_LAY_Y;
        FID2_LAY_Y = Rotation_buf;
        FID2_LAY_Y = FID2_LAY_Y * (-1);

        break;
    default :
        break;

    }

    //-------------------------------------------------------------------------------------------------//

    //-------------------------*** Apply shifting and zoom on FID ***----------------------------------//
    // FID1
    FID1_LAY_X = (FID1_LAY_X + Conf->DecalX) * this->ConfigData[Conf_Scale].toDouble();
    FID1_LAY_Y = (FID1_LAY_Y + Conf->DecalY) * this->ConfigData[Conf_Scale].toDouble();

    // FID2
    FID2_LAY_X = (FID2_LAY_X + Conf->DecalX) * this->ConfigData[Conf_Scale].toDouble();
    FID2_LAY_Y = (FID2_LAY_Y + Conf->DecalY) * this->ConfigData[Conf_Scale].toDouble();
    //-------------------------------------------------------------------------------------------------//

    for(int i = 0; i < *KiCADNumberOfLines; i++){

        //-----------------*** Converting strings to double to apply configurations ***--------------------//
        Comp_buf[i][PosX_buf] = strtod(comp[i].LocationX, NULL);
        Comp_buf[i][PosY_buf] = strtod(comp[i].LocationY, NULL);
        Comp_buf[i][Rot_buf] = strtod(comp[i].Rotation, NULL);
        //-------------------------------------------------------------------------------------------------//

        //-----------------------*** Converting the values from Inch to Mils ***---------------------------//
        //Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] * 1000;
        //Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * 1000;
        //-------------------------------------------------------------------------------------------------//

        //-----------------------*** Converting the values from mm to mils ***-----------------------------//
        Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] * 39.3701;
        Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * 39.3701;
        //-------------------------------------------------------------------------------------------------//

        //--------------------*** Adapting the KiCAD Values to match the PNP ones ***----------------------//
        Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] + 125;
        Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] + 7725;
        //Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * (-1);
        //-------------------------------------------------------------------------------------------------//

        //------------------------*** Adjusting the rotation of components ***-----------------------------//
        if(Comp_buf[i][Rot_buf] < 0) Comp_buf[i][Rot_buf] = Comp_buf[i][Rot_buf] + 360;
        //-------------------------------------------------------------------------------------------------//


        //-----------------------*** Apply shifting and zoom on components ***-----------------------------//
        Comp_buf[i][PosX_buf] = (Comp_buf[i][PosX_buf] - FID1_PCB_X) * this->ConfigData[Conf_Scale].toDouble();
        Comp_buf[i][PosY_buf] = (Comp_buf[i][PosY_buf] - FID1_PCB_Y) * this->ConfigData[Conf_Scale].toDouble();
        //-------------------------------------------------------------------------------------------------//

        //---------------------------*** Apply mirroring on components ***---------------------------------//
        if(Conf->Mirroir == 1) Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * (-1);
        //-------------------------------------------------------------------------------------------------//

        //---------------------------*** Apply Rotation on Components ***----------------------------------//
        Comp_buf[i][Rot_buf] = Comp_buf[i][Rot_buf] - 90; // since all components are loaded in 90 deg to the machine

        switch(((int) Conf->Angle)){
        case 90: // (x,y) => (-y,x)
            Rotation_buf = Comp_buf[i][PosX_buf];
            Comp_buf[i][PosX_buf] = Comp_buf[i][PosY_buf];
            Comp_buf[i][PosY_buf] = Rotation_buf;
            Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] * (-1);

            break;
        case 180: // (x,y) => (-x,-y)
            Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] * (-1);
            Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * (-1);

            break;
        case 270: // (x,y) => (y,-x)
            Rotation_buf = Comp_buf[i][PosX_buf];
            Comp_buf[i][PosX_buf] = Comp_buf[i][PosY_buf];
            Comp_buf[i][PosY_buf] = Rotation_buf;
            Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * (-1);

            break;
        default :
            break;

        }
        //-------------------------------------------------------------------------------------------------//

        //---------------------*** Adapting the component values to the MYDATA ***-------------------------//
        Comp_buf[i][PosX_buf] = round(Comp_buf[i][PosX_buf]);
        Comp_buf[i][PosY_buf] = round(Comp_buf[i][PosY_buf]);
        Comp_buf[i][Rot_buf] = Comp_buf[i][Rot_buf] * 1000;
        //-------------------------------------------------------------------------------------------------//

        //---------------*** Converting the values to string for writing in the file ***-------------------//
        snprintf(comp[i].LocationX, 2*sizeof(Comp_buf[i][PosX_buf]), "%d", (int) Comp_buf[i][PosX_buf]);
        //printf("LocationX : %s ; PosX : %lf\n", comp[i].LocationX, Comp_buf[i][PosX_buf]);
        snprintf(comp[i].LocationY, 2*sizeof(Comp_buf[i][PosY_buf]), "%d", (int) Comp_buf[i][PosY_buf]);
        //printf("LocationY : %s ; PosY : %lf\n", comp[i].LocationY, Comp_buf[i][PosY_buf]);
        snprintf(comp[i].Rotation, 2*sizeof(Comp_buf[i][Rot_buf]), "%d", (int) Comp_buf[i][Rot_buf]);
        //printf("Rotation : %s ; Rot : %lf\n", comp[i].Rotation, Comp_buf[i][Rot_buf]);
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

void CadData::ApplyConfigurations()
{
    double Rotation_buf;
    QList<QStringList> KiCADData_buf;
    double Comp_buf[this->KiCADNumberOfComponents][3];
    qInfo() << this->ConfigData[Conf_Rot].toInt();
    //--------------------------------*** Apply Rotation on FID_LAY ***------------------------------------//
    switch(this->ConfigData[Conf_Rot].toInt()){
    case 90: // (x,y) => (-y,x)
        // FID1
        Rotation_buf = FID1_LAY_X;
        FID1_LAY_X = FID1_LAY_Y;
        FID1_LAY_Y = Rotation_buf;
        FID1_LAY_X = FID1_LAY_X * (-1);

        // FID2
        Rotation_buf = FID2_LAY_X;
        FID2_LAY_X = FID2_LAY_Y;
        FID2_LAY_Y = Rotation_buf;
        FID2_LAY_X = FID2_LAY_X * (-1);

        break;
    case 180: // (x,y) => (-x,-y)
        // FID1
        FID1_LAY_X = FID1_LAY_X * (-1);
        FID1_LAY_Y = FID1_LAY_Y * (-1);

        // FID2
        FID2_LAY_X = FID2_LAY_X * (-1);
        FID2_LAY_Y = FID2_LAY_Y * (-1);

        break;
    case 270: // (x,y) => (y,-x)
        // FID1
        Rotation_buf = FID1_LAY_X;
        FID1_LAY_X = FID1_LAY_Y;
        FID1_LAY_Y = Rotation_buf;
        FID1_LAY_Y = FID1_LAY_Y * (-1);

        // FID2
        Rotation_buf = FID2_LAY_X;
        FID2_LAY_X = FID2_LAY_Y;
        FID2_LAY_Y = Rotation_buf;
        FID2_LAY_Y = FID2_LAY_Y * (-1);

        break;
    default :
        break;

    }

    //-------------------------------------------------------------------------------------------------//

    //-------------------------*** Apply shifting and zoom on FID ***----------------------------------//
    // FID1
    FID1_LAY_X = (FID1_LAY_X + this->ConfigData[Conf_OffsetX].toDouble()) * this->ConfigData[Conf_Scale].toDouble();
    FID1_LAY_Y = (FID1_LAY_Y + this->ConfigData[Conf_OffsetY].toDouble()) * this->ConfigData[Conf_Scale].toDouble();
    FID1_LAY_X = round(FID1_LAY_X);
    FID1_LAY_Y = round(FID1_LAY_Y);

    // FID2
    FID2_LAY_X = (FID2_LAY_X + this->ConfigData[Conf_OffsetX].toDouble()) * this->ConfigData[Conf_Scale].toDouble();
    FID2_LAY_Y = (FID2_LAY_Y + this->ConfigData[Conf_OffsetY].toDouble()) * this->ConfigData[Conf_Scale].toDouble();
    FID2_LAY_X = round(FID2_LAY_X);
    FID2_LAY_Y = round(FID2_LAY_Y);
    //-------------------------------------------------------------------------------------------------//

    KiCADData_buf = this->KiCADData;
    for (int i = 0; i < KiCADData_buf.size(); ++i) {
        KiCADData_buf[i].removeAt(Ref);
        KiCADData_buf[i].removeAt(Val-1);
        KiCADData_buf[i].removeAt(Package-2);
        KiCADData_buf[i].removeAt(Side-3);
    }
    //qInfo() << KiCADData_buf;

    for(int i = 0; i < this->KiCADNumberOfComponents; i++){

        //-----------------*** Converting strings to double to apply configurations ***--------------------//
        Comp_buf[i][PosX_buf] = KiCADData_buf[i][PosX_buf].toDouble();
        Comp_buf[i][PosY_buf] = KiCADData_buf[i][PosY_buf].toDouble();
        Comp_buf[i][Rot_buf] = KiCADData_buf[i][Rot_buf].toDouble();
        //-------------------------------------------------------------------------------------------------//

        //-----------------------*** Converting the values from Inch to Mils ***---------------------------//
        //Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] * 1000;
        //Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * 1000;
        //-------------------------------------------------------------------------------------------------//

        //-----------------------*** Converting the values from mm to mils ***-----------------------------//
        Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] * 39.37007;
        Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * 39.37007;
        //-------------------------------------------------------------------------------------------------//

        //--------------------*** Adapting the KiCAD Values to match the PNP ones ***----------------------//
        //Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] + 125;
        //Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] + 7725;
        //Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * (-1);
        //-------------------------------------------------------------------------------------------------//

        //------------------------*** Adjusting the rotation of components ***-----------------------------//
        if(Comp_buf[i][Rot_buf] < 0) Comp_buf[i][Rot_buf] = Comp_buf[i][Rot_buf] + 360;
        //-------------------------------------------------------------------------------------------------//


        //-----------------------*** Apply shifting and zoom on components ***-----------------------------//
        Comp_buf[i][PosX_buf] = (Comp_buf[i][PosX_buf] - FID1_PCB_X) * this->ConfigData[Conf_Scale].toDouble();
        Comp_buf[i][PosY_buf] = (Comp_buf[i][PosY_buf] - FID1_PCB_Y) * this->ConfigData[Conf_Scale].toDouble();
        //-------------------------------------------------------------------------------------------------//

        //---------------------------*** Apply mirroring on components ***---------------------------------//
        if(this->ConfigData[Conf_Mirror].toInt() == 1) Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * (-1);
        //-------------------------------------------------------------------------------------------------//

        //---------------------------*** Apply Rotation on Components ***----------------------------------//
        Comp_buf[i][Rot_buf] = Comp_buf[i][Rot_buf] - 90; // since all components are loaded in 90 deg to the machine

        switch(this->ConfigData[Conf_Rot].toInt()){
        case 90: // (x,y) => (-y,x)
            Rotation_buf = Comp_buf[i][PosX_buf];
            Comp_buf[i][PosX_buf] = Comp_buf[i][PosY_buf];
            Comp_buf[i][PosY_buf] = Rotation_buf;
            Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] * (-1);

            break;
        case 180: // (x,y) => (-x,-y)
            Comp_buf[i][PosX_buf] = Comp_buf[i][PosX_buf] * (-1);
            Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * (-1);

            break;
        case 270: // (x,y) => (y,-x)
            Rotation_buf = Comp_buf[i][PosX_buf];
            Comp_buf[i][PosX_buf] = Comp_buf[i][PosY_buf];
            Comp_buf[i][PosY_buf] = Rotation_buf;
            Comp_buf[i][PosY_buf] = Comp_buf[i][PosY_buf] * (-1);

            break;
        default :
            break;

        }
        //-------------------------------------------------------------------------------------------------//

        //---------------------*** Adapting the component values to the MYDATA ***-------------------------//
        Comp_buf[i][PosX_buf] = round(Comp_buf[i][PosX_buf]);
        Comp_buf[i][PosY_buf] = round(Comp_buf[i][PosY_buf]);
        Comp_buf[i][Rot_buf] = Comp_buf[i][Rot_buf] * 1000;
        //-------------------------------------------------------------------------------------------------//

        //---------------*** Converting the values to string for writing in the file ***-------------------//
        this->KiCADData[i][PosX] = QString("%1").arg((int) Comp_buf[i][PosX_buf]);
        this->KiCADData[i][PosY] = QString("%1").arg((int) Comp_buf[i][PosY_buf]);
        this->KiCADData[i][Rot] = QString("%1").arg((int) Comp_buf[i][Rot_buf]);
        // qInfo() << "Converting the values to string for writing in the file" << "\n";
        // qInfo() << "Double : " << Comp_buf[i][PosX_buf] << " QString : " << this->KiCADData[i][PosX];
        // qInfo() << "Double : " << Comp_buf[i][PosY_buf] << " QString : " << this->KiCADData[i][PosY];
        // qInfo() << "Double : " << Comp_buf[i][Rot_buf] << " QString : " << this->KiCADData[i][Rot];
        //-------------------------------------------------------------------------------------------------//

    }

    emit sendLayData((int) this->FID1_LAY_X, (int) this->FID1_LAY_Y, (int) this->FID2_LAY_X, (int) this->FID2_LAY_Y);
    emit sendPcbData(this->FID1_PCB_X, this->FID2_PCB_X, this->ConfigData[Conf_Scale].toDouble(), this->KiCADData, this->UsedLibData);
}

void CadData::FindFiducials(QStringList _KiCADData)
{
    if(_KiCADData[0].contains("FID1")){
        FID1_X = _KiCADData[PosX].toDouble();
        FID1_Y = _KiCADData[PosY].toDouble();
        FID1_X = FID1_X * 39.37007;
        FID1_X = round(FID1_X);
        // Applying mirroring for KiCAD
        //FID1_Y = FID1_Y * (-1);
        FID1_Y = FID1_Y * 39.37007;
        FID1_Y = round(FID1_Y);


        FID1_PCB_X = FID1_X;
        FID1_PCB_Y = FID1_Y;
        FID1_LAY_X = FID1_X;
        FID1_LAY_Y = FID1_Y;
        //qInfo() << "FID1 => " <<"PosX : " << FID1_X << "PosY : " << FID1_Y;

    }
    if(_KiCADData[0].contains("FID2")){
        FID2_X = _KiCADData[PosX].toDouble();
        FID2_Y = _KiCADData[PosY].toDouble();
        // Inch to Mils
        //FID2_X = FID2_X * 1000;
        FID2_X = FID2_X * 39.37007;
        FID2_X = round(FID2_X);
        // Inch to Mils
        //FID2_Y = FID2_Y * 1000;
        // Applying mirroring for KiCAD
        //FID2_Y = FID2_Y * (-1);
        FID2_Y = FID2_Y * 39.37007;
        //if(Conf->Mirroir == 0) FID2_PCB_Y = FID2_PCB_Y * (-1);
        FID2_Y = round(FID2_Y);


        FID2_PCB_X = FID2_X;
        FID2_PCB_Y = FID2_Y;
        FID2_LAY_X = FID2_X;
        FID2_LAY_Y = FID2_Y;
        //qInfo() << "FID2 => " <<"PosX : " << FID2_X << "PosY : " << FID2_Y;
    }

}


void CadData::getCadConfigData(QString _ConfigData)
{
    this->ConfigData << _ConfigData;
    qInfo() << "CAD : " << ConfigData;
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
    ApplyConfigurations();
}

void CadData::getKiCADData(QList<QStringList> _KiCADData, int _KiCADNumberOfComponents)
{
    this->KiCADData = _KiCADData;
    this->KiCADNumberOfComponents = _KiCADNumberOfComponents;
    //qInfo() << this->KiCADData.size();
    for (int i = 0; i < _KiCADNumberOfComponents; i++) {
        FindFiducials(_KiCADData[i]);
    }

}

void CadData::getKiCADNumberOfLines(int _KiCADNumberOfLines)
{
    this->KiCADNumberOfLines = _KiCADNumberOfLines;
    //qInfo() << " KiCAD Number of Lines : " << this->KiCADNumberOfLines;
}


