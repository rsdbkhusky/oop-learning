//
// Created by lenovo on 2024/11/6.
//

#ifndef PROBLEM7_EXTSTRING_H
#define PROBLEM7_EXTSTRING_H

class ExtString {
public:
    ExtString concat( const ExtString & other, const ExtString & interval ="" ) const;
    ExtString & append( const ExtString & other );
};

#endif //PROBLEM7_EXTSTRING_H
