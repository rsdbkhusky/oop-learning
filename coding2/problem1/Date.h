//
// Created by lenovo on 2024/11/5.
//

#ifndef CODING2_DATE_H
#define CODING2_DATE_H

class Date {
public:
    Date(int y,int m,int d):year(y),month(m),day(d) { }
    void print( ) const;
    //修改本date为nMonths个月后的今天(nMonth可取负)，
    //若结果为非法日期,则为当月最后一天，
    //如当前为2020年3月31日，nMonth为1，则日期为2020年4月30日
    void plusMonths(int nMonths);
    void plusDays(int nDays);
private:
    int year;
    int month;
    int day;
};

#endif //CODING2_DATE_H
