#pragma once

#include <QObject>
#include <QMutex>
#include <QMap>

#define DATA StaticData::instance()

class StaticData : public QObject
{
    Q_OBJECT
    // Singleton code
public:
    static StaticData* instance()
    {
        static QMutex mutex;
        if (!_instance)
        {
            mutex.lock();

            if (!_instance)
            {
                _instance = new StaticData;
            }
            mutex.unlock();
        }

        return _instance;
    }

    static void drop()
    {
        static QMutex mutex;
        mutex.lock();
        delete _instance;
        _instance = 0;
        mutex.unlock();
    }

private:
    StaticData(QObject *parent = 0);

    StaticData(const StaticData &); // hide copy constructor
    StaticData& operator=(const StaticData &); // hide assign op
                                 // we leave just the declarations, so the compiler will warn us
                                 // if we try to use those two functions by accident

    static StaticData* _instance;

public:
    void init();

    QList<int> elementIds() const;
    QString elementName(const int element);
    int elementId(const QString elementName);

    QList<QString> elementNames() const;
private:
    void addElement(const int id, const QString elementName);

    QMap<int, QString> m_elements;
    QMap<QString, int> m_elementsIndex;

};

