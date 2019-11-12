#include "window.h"

Window::Window(int w_len, int frame_len){
    this->frame_len = frame_len;
    this->w_len = w_len;
    ventana = new char*[w_len];
    status = new bool[w_len];
    for(int i = 0; i<w_len; i++){
        ventana[i] = new char[frame_len];
    }
    nMin = 0;
    item_counter = 0;
    last_filled = -1;
}

Window::~Window(){
    for (int i = 0; i < w_len; i++) {
        delete ventana[i];
    }
    delete ventana;
    delete status;
};

int Window::put(int num_package,char * source){
    if (nMin <= num_package && ((nMin)+w_len) > num_package) {
        int pivote = num_package%w_len;
        if (!status[pivote]) {
            status[pivote]=true;
            last_filled=num_package;
            copy_to_me(pivote, source);
            item_counter++;
        }
        return 1;
    }
    return 0;
}

void Window::copy_to_me(int pivote, char * source){
    for (int i = 0; i < frame_len; i++) {
        ventana[pivote][i]=source[i];
    }
}

int Window::get_recv(char *dest){
    int pivote = nMin%w_len;
    if (status[pivote]) {
        copy_to_others(dest,ventana[pivote]);
        status[pivote] = false;
        nMin ++;
        item_counter--;
        return 1;
    }
    return 0;
};

void Window::copy_to_others(char * dest, char * source){
    for(int i=0; i<frame_len; i++){
        dest[i] = source[i];
    }
};

void Window::check_status(){
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    printf(" Size:%d\n Item accounter:%d\n nMin:%d\n Last filled:%d\n",
    w_len, item_counter, nMin, last_filled);
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    return;
}

void Window::print(){
    for (int i = 0; i < w_len; i++) {
        if(status[i]){
            cout << "EN LA POSICIÓN " << i << " ESTÁ: " << ventana[i] << endl;
        }
        cout << "EN LA POSICIÓN " << i << " ESTÁ: VACÍA" << endl;
    }
    return;
};

int Window::get_send(char * dest, int num_package){
    int pivote = num_package%w_len;
    if (nMin <= num_package && ((nMin+w_len) > num_package) && status[pivote]) {
        copy_to_others(dest,ventana[pivote]);
        return 1;
    }
    return 0;
}

int Window::get_nMin(){
    return nMin;
}

int Window::get_W_len(){
    return w_len;
}

bool Window::empty(){
    if (item_counter) {
        return false;
    }
    return true;
}

int Window::get_last(){
    return last_filled;
}

int Window::get_frame_len(){
    return frame_len;
}

void Window::set_nMin(int num_package){
    int pivote = 0;
    for (int i = nMin; i < (nMin+w_len); i++) {
        pivote = i%w_len;
        if (i < num_package && status[pivote]) {
            status[pivote] = 0;
            item_counter--;
        }
    }
    nMin = num_package;
    last_filled = nMin-1;
}
