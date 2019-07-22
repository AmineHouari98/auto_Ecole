#ifndef MYPARENTOBJECT_H
#define MYPARENTOBJECT_H

#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSettings>
#include <QDir>
#include <QTimer>
#include <QApplication>
#include <QLineEdit>


class MyParentObject
{
public:
    MyParentObject();
    ~MyParentObject();

    QString convertWhidaToLetter(QString whida, int position);
    QString spellLetter(QString number);
    QString champVide = "completez les champs manquants s'il vous plaît";

    bool msgQuestion(QString title, QString body);
    void msgCritical(QString title, QString body);
    void msgInformation(QString title, QString body);
    void msgWarning(QString title, QString body);

    void setSettings(QString key, QVariant data);
    QVariant getSettings(QString key);
    int checkIntegrity(QList<QLineEdit*>);
    static void chiffreEnLettre(unsigned int chiffre, char *lettre);
    static QString result(int number);
    static QString addcommat(unsigned long long n);
private:
    QSettings *_mySettings;
    QString thisPath, settingsFilePath ;
    QTimer tm;
};

#endif // MYPARENTOBJECT_H
