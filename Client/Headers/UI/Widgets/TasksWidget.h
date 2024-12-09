#ifndef ADAPTIXCLIENT_TASKSWIDGET_H
#define ADAPTIXCLIENT_TASKSWIDGET_H

#include <main.h>
#include <QStyledItemDelegate>

class PaddingDelegate : public QStyledItemDelegate {
public:
    explicit PaddingDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        opt.rect.adjust(15, 0, -15, 0);

        QStyledItemDelegate::paint(painter, opt, index);
    }

    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QSize originalSize = QStyledItemDelegate::sizeHint(option, index);
        return QSize(originalSize.width() + 30, originalSize.height());
    }
};

class TaskOutputWidget : public QWidget
{
    QGridLayout* mainGridLayout = nullptr;
    QLabel*      label          = nullptr;
    QLineEdit*   inputMessage   = nullptr;
    QTextEdit*   outputTextEdit = nullptr;

    void createUI();

public:
    explicit TaskOutputWidget( );
    ~TaskOutputWidget();

    void SetConten(QString message, QString text);
};



class TasksWidget : public QWidget
{
    QWidget*      mainWidget        = nullptr;
    QGridLayout*  mainGridLayout    = nullptr;
    QTableWidget* tableWidget       = nullptr;

    void createUI();

public:
    TaskOutputWidget* taskOutputConsole = nullptr;

    explicit TasksWidget( QWidget* w );
    ~TasksWidget();

    void Clear();
    void AddTaskItem(TaskData newTask);
    void EditTaskItem(TaskData newTask);
    void RemoveTaskItem(QString taskId);

public slots:
    void handleTasksMenu( const QPoint &pos );
    void onTableItemSelection();
};

#endif //ADAPTIXCLIENT_TASKSWIDGET_H
