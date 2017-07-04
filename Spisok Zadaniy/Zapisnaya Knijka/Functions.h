#pragma once
void disp_list(char **str, int w, short &col);
void add_cont(char **&str, int &w, int h);
void sort_cont(char **str, int w, int h);
void delete_cont(char **&str, int &w, int h, int contact_number);
void edit_cont(char **str, int w, int h, int contact_number);
void hideCursor(bool switch_cursor = false);
void search_cont(char **str, int w, int h);
