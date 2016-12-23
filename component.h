#pragma once

#include <QObject>
#include <QVariant>
#include <QJsonObject>

class Component : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int element READ element CONSTANT FINAL)
    Q_PROPERTY(QString name READ name CONSTANT FINAL)
    Q_PROPERTY(QVariant value READ value WRITE setValue)

public:
    Component(int element, QVariant value=QVariant(), QObject *parent = 0);

    int element() const;
    QString name() const;

    QVariant value() const;
    void setValue(QVariant value);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

signals:

public slots:

private:
    int m_element;
    QVariant m_value;
};
