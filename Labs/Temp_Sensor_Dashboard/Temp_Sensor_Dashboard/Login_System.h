/*
 * Login_System.h
 *
 *  Created on: Mar 21, 2024
 *      Author: Hassan Bahnasy
 */

#ifndef LOGIN_SYSTEM_H_
#define LOGIN_SYSTEM_H_




/* Function prototypes */
void appenedToBuffer(u8 *buffer,u8 key);
void ClearBuffer(u8 *buffer,u8 size);
void CheckPassword(u8* buffer,u8* password,u8* Result);
void login_system(const u8* password, u8* flag);


#endif /* LOGIN_SYSTEM_H_ */
