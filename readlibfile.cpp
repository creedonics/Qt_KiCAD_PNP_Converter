#include "readlibfile.h"

/*
int ReadingMydataLibFile(const char* MydataLibFilePath, struct LibFile* Lib, struct CadComponent* comp, int* KiCADNumberOfLines){

    char* Fiducial1 = "FID1";
    char* Fiducial2 = "FID2";
    int n = 0;
    // Lib File Numb of elements counter
    int LibElemCount = 0;
    // Lib File Numb of lines counter
    int LibLineCount = 0;
    // Buffer to store each line of the Config file.
    char LibFileLine[LineCharLength];
    // Sub-Strings returned by strtok
    char* LibFileToken;
    // buffer to store the Sub-Strings
    char TempLibFileVal[LibFileNumbLines][LineCharLength];
    // Delimiter characters for strpbrk & strtok
    char LibFileComments[] = "#[";
    char LibFileDelimit[] = ";";
    // Open File MydataConfigFile.ini in reading mode
    MydataLibFile = fopen(MydataLibFilePath, "r");
    if (MydataLibFile != NULL){
        // Writing to the File
        while (fgets(LibFileLine, sizeof(LibFileLine), MydataLibFile)) {
            if (strpbrk(LibFileLine, LibFileComments) == NULL) {
                if ((LibFileToken = strtok(LibFileLine, LibFileDelimit)) != NULL) {
                    do {
                            strcpy (TempLibFileVal[LibElemCount], LibFileToken);
                            LibElemCount++;
                            if(LibElemCount % 7 == 0) LibLineCount++;
                            // now, the while continuation condition grabs the
                            // next token (by passing NULL as the first param)
                            // and continues if the token's not NULL:
                    } while ((LibFileToken = strtok(NULL, LibFileDelimit)) != NULL);
                }
            }
        }
        for(int i = 0; i < *KiCADNumberOfLines; i++){
            for(int j = 1; j <= LibLineCount; j++){
                if(!((strcmp(comp[i].RefDes, Fiducial1) == 0) || (strcmp(comp[i].RefDes, Fiducial2) == 0))){
                    if((strcmp(comp[i].Type, TempLibFileVal[(j-1)*7]) == 0) && (strcmp(comp[i].Value, TempLibFileVal[1+(j-1)*7]) == 0)){
                        Lib[n].CmpName = TempLibFileVal[2+(j-1)*7];
                        Lib[n].PriorityGroup = TempLibFileVal[3+(j-1)*7];
                        Lib[n].MountSkip = TempLibFileVal[4+(j-1)*7];
                        Lib[n].DispenseSkip = TempLibFileVal[5+(j-1)*7];
                        n++;
                    }
                //else{
                //    printf("Component %s was not found in Lib file", comp[i].Type);
                //}
                }
            }
        }
    }
    else {
        printf("Unable to open MydataLibFile.lib file");
        exit(EXIT_FAILURE);
    }
    // close file
    fclose(MydataLibFile);

    return EXIT_SUCCESS;
}
*/

ReadLibFile::ReadLibFile(QObject *parent)
    : QObject{parent}
{}

void ReadLibFile::readingMydataLibFile()
{
    QFile file(this->LibFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    int LibFileNumberOfLines = 0;
    QList<QStringList> LibData;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.indexOf("#") == -1) {
            //qInfo() << line.split(";");
            LibFileNumberOfLines++;
            LibData << line.split(";");
        }
    }
    emit sendLibData(LibData ,LibFileNumberOfLines);
}
