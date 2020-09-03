//
// Created by admin on 06/07/2020.
//

#include "network/connection.h"
#include <mutex>

int a=0;

struct AddArgument {
    int num;
};

struct AddResponse {
    int num;
};

void AddNumber(AddArgument *arg,AddResponse *resp) {
    a += arg->num;
    resp->num = a;
    return;
}

int main() {
    Connection myConnection;
    myConnection.StartListen(8080);
    return 0;
}

/*
 * RPC: register a function for remote procedures to call. RPC not responsible for thread safety.
 * RPC: accept a RPC call that it will deliver, and it will also deliver the response back.
 * RPC client: this is the thing that will deliver calls
 * RPC server: this will call the function
 *
 * server  Connection serialize function, args <-   serialized response      Connection
 * RPC server   function, args <-   ->resp   RPC client: perform serialize and deserialize
 * server   function, args, resp       client
 *
 * Connection Layer: start listening, given socket is, send.
 * RPC layer: client: synchrounous: send RPC, blocks until reply is received -> (blocking queue? Callback? (polling vs interrupt))
 *            server: receive RPC, and send reply back
 * server, client...
 *
 */