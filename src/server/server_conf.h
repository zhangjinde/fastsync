/**
* server_conf.h
*
* Init Created: 2016-07-04
* Last Updated: 2016-07-04
*/
#ifndef SERVER_CONF_H_INCLUDED
#define SERVER_CONF_H_INCLUDED

#include "../xmlconf.h"

#if defined(__cplusplus)
extern "C" {
#endif


/**
* server_conf_t is static instance in main process.
*   populated with config xml file: server.xml
*/
typedef struct server_conf_t
{
    char ver[10];

    /**
    * authentication
    */
    char magic[FSYNC_MAGIC_LEN + 1];
    int ssl_enabled;
    char pubkey[1];
    char privkey[1];

    /**
    * stash
    */
    char pathprefix[FSYNC_PATHPREFIX_LEN + 1];
    int backend;
    union {
        /* backend: sqlite3 */
        struct {
            int maxretry;
            int interval;
        };
    };

    /**
    * tcp connection
    */
    int backlog;

    char *iptable_whitelist;
    char *iptable_blacklist;

    unsigned short port;
    int maxclients;
    int bufsize;
    int timeout;
    int keepinterval;
    int keepidle;
    int keepcount;
    int nodelay;

    /**
    *  autoupdate
    */
    int autoupdate;
    char clientpkg_md5sum[FSYNC_MD5SUM_LEN + 1];
    char clientpkg[FSYNC_PKGNAME_LEN + 1];
} server_conf_t;


extern int server_conf_create(const char * cfgfile, server_conf_t **ppOut);

extern void server_conf_free (server_conf_t ** srvconf);

extern void server_conf_print (server_conf_t * srvconf);

#if defined(__cplusplus)
}
#endif

#endif /* SERVER_CONF_H_INCLUDED */
