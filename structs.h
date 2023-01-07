#ifndef _STRUCTS_H
#define _STRUCTS_H

/**
 * struct alias - contains shell aliases
 * @alias_name: alais name of command
 * @real_name: real name of command alias
 * Description: this struct is used to store aliases and info
 */
typedef struct alias
{
	char *alias_name;
	char *real_name;
} alias;

#endif /*_STRUCTS_H*/
