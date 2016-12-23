#include "component.h"
#include "staticdata.h"

Component::Component(int element, QVariant value, QObject *parent)
    : QObject(parent), m_element(element), m_value(value)
{
}


int Component::element() const
{
    return m_element;
}

QString Component::name() const
{
    return DATA->elementName(m_element);
}

QVariant Component::value() const
{
    return m_value;
}

void Component::setValue(QVariant value)
{
    m_value = value;
}

void Component::read(const QJsonObject &json)
{
    m_element = json["element"].toInt();
    m_value = QVariant(json["value"]);
}

void Component::write(QJsonObject &json) const
{
    json["element"] = m_element;
    json["value"] = m_value.toJsonValue();
}
