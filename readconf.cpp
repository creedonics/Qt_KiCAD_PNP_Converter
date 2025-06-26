#include "readconf.h"

/*//-------------------------------------------------------------------------------------------------//
//----------------------------*** Reading from MydataConfigFile ***--------------------------------//
//-------------------------------------------------------------------------------------------------//

int ReadingMydataConfigFile(const char* MydataConfigFilePath, struct ConfigFile *Conf){
    int i = 0;
    // Buffer to store each line of the Config file.
    char ConfigFileLine[LineCharLength];
    // Sub-Strings returned by strtok
    char *ConfigFileToken;
    // buffer to store the Sub-Strings
    double TempConfigFileVal[ConfigFileNumbLines];
    // Delimiter characters for strpbrk & strtok
    char ConfigFileComments[] = "#[";
    char ConfigFileDelimit[] = " =";
    // Open File MydataConfigFile.ini in reading mode
    MydataConfigFile = fopen(MydataConfigFilePath, "r");
    if (MydataConfigFile != NULL){
        // Writing to the File
        while (fgets(ConfigFileLine, sizeof(ConfigFileLine), MydataConfigFile)) {
            if (strpbrk(ConfigFileLine, ConfigFileComments) == NULL)
            {
                if ((ConfigFileToken = strtok(ConfigFileLine, ConfigFileDelimit)) != NULL) {
                    do {
                        if (strtod(ConfigFileToken, NULL) != 0)
                        {
                            TempConfigFileVal[i] = strtod(ConfigFileToken, NULL);
                            switch (i)
                            {
                            case 0:
                                Conf->DecalX = TempConfigFileVal[i];
                                break;
                            case 1:
                                Conf->DecalY = TempConfigFileVal[i];
                                break;
                            case 2:
                                Conf->Zoom = TempConfigFileVal[i];
                                break;
                            case 3:
                                Conf->Angle = TempConfigFileVal[i];
                                break;
                            case 4:
                                Conf->Mirroir = (int) TempConfigFileVal[i];
                                break;
                            default:
                                break;
                            }
                            i++;
                        }
                        // now, the while continuation condition grabs the
                        // next token (by passing NULL as the first param)
                        // and continues if the token's not NULL:
                    } while ((ConfigFileToken = strtok(NULL, ConfigFileDelimit)) != NULL);
                }
            }
        }
    }
    else {
        printf("Unable to open MydataConfigFile.ini file");
        exit(EXIT_FAILURE);
    }
    // close file
    fclose(MydataConfigFile);

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------------------------------------------//*/

ReadConf::ReadConf(QObject *parent)
    : QObject{parent}
{}

void ReadConf::ReadingMydataConfigFile(QString _FilePath)
{
    QFile file(_FilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        //QString testing;
        int i;
        if(line.indexOf("=") != -1) {
            i = line.indexOf("=");
            qInfo() << line.sliced(i + 2);
            emit sendCadConfigData(line.sliced(i + 2));
        }
    }
}

void ReadConf::getFilePathUrl(QUrl _FilePathUrl)
{
    this->FilePath = _FilePathUrl.toLocalFile();
    ReadingMydataConfigFile(this->FilePath);

}
