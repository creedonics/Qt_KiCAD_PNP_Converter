#include "writelay.h"

/*
//-------------------------------------------------------------------------------------------------//
//-------------------------------*** writing to MydataLayFile ***----------------------------------//
//-------------------------------------------------------------------------------------------------//

int WritingMyDataLayFile(const char* CadProjectName, struct ConfigFile* Conf, struct FID* FID1_LAY, struct FID* FID2_LAY){

    MydataLayFile = fopen("MydataLayFile.lay", "w");

    if(MydataLayFile != NULL){
        fprintf(MydataLayFile, "S1 %s\n", CadProjectName);
        for(int i = 0; i < 10; i++) fprintf(MydataLayFile, "S2\n");
        fprintf(MydataLayFile, "S3B %s\n", CadProjectName);
        fprintf(MydataLayFile, "S4M tp11n242\n");
        fprintf(MydataLayFile, "S4 %d %d %d %d 0 0\n", (int) FID1_LAY->pos_x, (int) FID1_LAY->pos_y, (int) FID2_LAY->pos_x, (int) FID2_LAY->pos_y);
    }
    else{
        fprintf(stderr, "Unable to open MydataLayFile.lay file!\n");
        exit(EXIT_FAILURE);
    }

    fclose(MydataLayFile);

    return EXIT_SUCCESS;

}

//-------------------------------------------------------------------------------------------------//
*/

WriteLay::WriteLay(QObject *parent)
    : QObject{parent}
{}

void WriteLay::WritingMyDataLayFile()
{
    QFile file("MydataLayFile.lay");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "S1 " << "CadProjectName" << "\r\n";
    for (int i = 0; i < 10; ++i) {
        out << "S2" << "\r\n";
    }
    out << "S3B " << "CadProjectName" << "\r\n";
    out << "S4M tp11n242" << "\r\n";
    out << "S4 " << " " << this->FID1_LAY_X << " " << this->FID1_LAY_Y << " " << this->FID2_LAY_X << " " << this->FID2_LAY_Y << " 0" << " 0" << "\r\n";

    //qInfo() << "Finished Writing to MydataLayFile.lay";
}

void WriteLay::getLayData(int _FID1_LAY_X, int _FID1_LAY_Y, int _FID2_LAY_X, int _FID2_LAY_Y)
{
    this->FID1_LAY_X = _FID1_LAY_X;
    this->FID1_LAY_Y = _FID1_LAY_Y;
    this->FID2_LAY_X = _FID2_LAY_X;
    this->FID2_LAY_Y = _FID2_LAY_Y;
    WritingMyDataLayFile();
}



