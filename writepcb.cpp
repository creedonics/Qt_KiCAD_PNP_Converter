#include "writepcb.h"

/*
//-------------------------------------------------------------------------------------------------//
//-------------------------------*** writing to MydataPcbFile ***----------------------------------//
//-------------------------------------------------------------------------------------------------//

int WritingMyDataPcbFile(const char* CadProjectName, struct ConfigFile* Conf, struct CadComponent* comp, int* KiCADNumberOfLines, struct FID* FID1_PCB, struct FID* FID2_PCB, struct LibFile* Lib){
    int j = 0;
    char* Fiducial1 = "FID1";
    char* Fiducial2 = "FID2";
    MydataPcbFile = fopen("MydataPcbFile.pcb", "w");
    for(int i = 0; i < *KiCADNumberOfLines - 2; i++){
        printf("PriorityGroup : %s from Comp : %s\n", Lib[i].PriorityGroup, Lib[i].CmpName);
    }

    if(MydataPcbFile != NULL){
        fprintf(MydataPcbFile, "F1 %s\n", CadProjectName);
        fprintf(MydataPcbFile, "F2 %s\n", "DATE");
        fprintf(MydataPcbFile, "F3 0 0\n");
        fprintf(MydataPcbFile, "F3 %d 0\n", (int) ((FID2_PCB->pos_x - FID1_PCB->pos_x) *  Conf->Zoom));
        fprintf(MydataPcbFile, "F4 0 0\n");
        fprintf(MydataPcbFile, "F5 10 20\n");
        fprintf(MydataPcbFile, "F6 10 -20\n");
        fprintf(MydataPcbFile, "F7 10 40\n");

        for (int i = 0; i < *KiCADNumberOfLines; i++){
            if(!((strcmp(comp[i].RefDes, Fiducial1) == 0) || (strcmp(comp[i].RefDes, Fiducial2) == 0))){
                printf("F8 %s %s %s %s %s %s %s\n",
                       comp[i].LocationX,
                       comp[i].LocationY,
                       comp[i].Rotation,
                       Lib[j].PriorityGroup,
                       Lib[j].MountSkip,
                       Lib[j].DispenseSkip,
                       Lib[j].CmpName);

                fprintf(MydataPcbFile, "F8 %s %s %s %s %s %s %s\n",
                        comp[i].LocationX,
                        comp[i].LocationY,
                        comp[i].Rotation,
                        Lib[j].PriorityGroup,
                        Lib[j].MountSkip,
                        Lib[j].DispenseSkip,
                        Lib[j].CmpName);
                j++;
            }
        }
        j = 0;
    }
    else{
        fprintf(stderr, "Unable to open MydataPcbFile.pcb file!\n");
        exit(EXIT_FAILURE);
    }

    fclose(MydataPcbFile);

    return EXIT_SUCCESS;

}
//-------------------------------------------------------------------------------------------------//
*/

WritePcb::WritePcb(QObject *parent)
    : QObject{parent}
{}

void WritePcb::WritingMyDataPcbFile()
{
    QFile file("MydataPcbFile.pcb");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "F1 " << "CadProjectName" << "\r\n";
    out << "F2 " << "DATE" << "\r\n";
    out << "F3 0 0" << "\r\n";
    out << "F3 " << (this->FID2_PCB_X - this->FID1_PCB_X) * this->ConfigData_Scale << " 0" << "\r\n";
    out << "F4 0 0" << "\r\n";
    out << "F5 10 20" << "\r\n";
    out << "F6 10 -20" << "\r\n";
    out << "F7 10 40" << "\r\n";

    for (int i = 0; i < this->KiCADData.size(); i++) {
        out << QString("F8 %1 %2 %3 %4 %5 %6 %7").arg(this->KiCADData[i][PosX]).arg(this->KiCADData[i][PosY]).arg(this->KiCADData[i][Rot]).arg(this->UsedLibData[i][prioritée]).arg(this->UsedLibData[i][montage]).arg(this->UsedLibData[i][colle]).arg(this->UsedLibData[i][nomMYDATA]) << "\r\n";
    }
}

void WritePcb::getPcbData(int _FID1_PCB_X, int _FID2_PCB_X, double _ConfigData_Scale, QList<QStringList> _KiCADData, QList<QStringList> _UsedLibData)
{
    this->FID1_PCB_X = _FID1_PCB_X;
    this->FID2_PCB_X = _FID2_PCB_X;
    this->ConfigData_Scale = _ConfigData_Scale;
    for (int i = 0; i < _KiCADData.size(); i++) {
        if( _KiCADData[i][Ref] == "FID1" || _KiCADData[i][Ref] == "FID2" ) {
            _KiCADData.removeAt(i);
            i--;
            //qInfo() << _KiCADData;
        }
    }
    this->KiCADData = _KiCADData;
    this->UsedLibData = _UsedLibData;
    WritingMyDataPcbFile();
}
