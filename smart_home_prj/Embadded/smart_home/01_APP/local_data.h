/*
 * local_data.h
 *
 *  Created on: Mar 2, 2022
 *      Author: hassan
 */

#ifndef _APP_LOCAL_DATA_H_
#define _APP_LOCAL_DATA_H_

typedef  struct user
{
    u8 name[25];
    u8 password[25];
}user;

user array[10] =
{
        {"hassan sayed"  ,"9131"},
        {"mariam magdy"  ,"7441"},
        {"mariam farouk" ,"7471"},
		{"amr ali"       ,"1234"},
        {"mona saad"     ,"1234"},
        {"ahmed ali"     ,"1234"},
        {"khaled ali"    ,"1234"},
        {"nada ahmed"    ,"1234"},
        {"ali ahmed"     ,"1234"},
        {"tamer mohsen"  ,"1234"},
};



#endif /* _APP_LOCAL_DATA_H_ */
