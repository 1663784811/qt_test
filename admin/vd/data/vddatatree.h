#ifndef VDDATATREE_H
#define VDDATATREE_H

/**
 * 森林数据结构
 */
#include <QString>

template <typename T>

class VdDataTree
{
public:
    VdDataTree() {

    }

    QString insertData(T *t ,T *parent);  // 插入一个数据反回一个ID

    T* getByKey(QString key);  //



private:


};

#endif // VDDATATREE_H
