#include "staticdata.h"

StaticData* StaticData::_instance = 0;

StaticData::StaticData(QObject *parent) : QObject(parent)
{
}

void StaticData::init()
{
    addElement(0, "Eka");
    addElement(2, "Pitkä nimi");
    addElement(3, "Kolmas");
    addElement(6, "Vika");

}

QList<int> StaticData::elementIds() const
{
    return m_elements.keys();
}

QList<QString> StaticData::elementNames() const
{
    return m_elementsIndex.keys();
}

QString StaticData::elementName(const int element)
{
    return m_elements.value(element);
}

int StaticData::elementId(const QString elementName)
{
    if (m_elementsIndex.contains(elementName))
    {
        return m_elements.key(elementName);
    }

    int newId;
    do {
        newId = qrand();
    } while (m_elements.contains(newId));

    m_elements.insert(newId, elementName);
    m_elementsIndex.insert(elementName, newId);
    return newId;
}

void StaticData::addElement(const int id, const QString elementName)
{
    m_elements.insert(id, elementName);
}
