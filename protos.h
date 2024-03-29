void            getmessage(void *c, const char *who, const int automessage, const char *message);
void            buddy_idle(void *c, const char *who, long idletime);
void            buddy_away(void *c, const char *who);
void            buddy_unaway(void *c, const char *who);
void            buddy_online(void *c, const char *who);
void            remove_from_list(const char *who);
void            buddy_offline(void *c, const char *who);
void            buddy_profile(void *c, const char *who, const char *msg);
void            buddy_awaymsg(void *c, const char *who, const char *msg);
void            delete_buddylist(struct BuddyList * buddylist);
void            read_away_messages(void);
void            addtoinputbuf(char inchr);
void            setup_tty(void);
void            restore_tty(void);
void            show_prompt(void);
void            sigwinch_handler(int a);
void            sigint_handler(int a);
void            sigusr1_handler(int a);
void            set_profile(void *handle);
void            set_icon(void *handle);
void            load_buddylist(void *handle);
void            error_callback(void *handle, int event, uint32_t data);
void            handle_deleted(void *handle);
void            b_getusername(void);
void            b_getpassword(void);
char           *undo_netspeak(char *orig);
int             read_conf(void);
int             bl_get_confopt(char *filename, struct ConfigOptions * opts);
int             bl_conf_bool(char *arg);
void           *create_new_connection(void);
void            receive_formatted_sn(void *handle, char *sn);
void            parse_input(void);
void            input_quit(char *arg);
void            input_reload_profile(char *arg);
void            input_send_message(char *arg);
void            input_paste(char *arg);
void            input_show_buddies(char *arg);
void            input_show_help(char *arg);
void            input_show_log(char *arg);
void            input_add_buddy(char *arg);
void            input_delete_buddy(char *arg);
void            input_set_invisible(char *arg);
void            input_set_away(char *arg);
void            input_get_info(char *arg);
void            input_get_away(char *arg);
void            input_get_profile(char *arg);
void            input_set_predefaway(char *arg);
ssize_t         bsf_getline(char *str, int size);
void            input_reconnect(char *arg);
int             open_log_dir(void);
void            log_event(int event_type, char *sn, char *msg);
void            show_log(int lines, char *sn);
void            log_buddies_offline(void);
void            addts(void);
void            eraseline(void);
void            get_screen_size(void);
void            wordwrap_print(char *str, int offset);
void            wordwrap_print_echostr(char *str, char *echostr);
void            set_color(int color);
void            display_buddylist(void);
void            display_buddylist_sorted(void);
void            printspaces(int num);
void            prettyprint(char *ptext, int offset);
void            prettyprint_echostr(char *ptext, char *echostr);
void            set_title(char *title);
int             getwidth(void);
struct MessageQueue *addToMQueue(struct MessageQueue * head, char *message, char *whom);
void            clearMQueue(struct MessageQueue * head);
char           *simplify_sn(const char *sn);
char           *strip_html(const char *message);
