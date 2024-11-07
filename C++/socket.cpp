#include <iostream>
#include<boost/asio.hpp>
using boost::asio::ip::udp;
int main(int argc, char const *argv[])
{
    try {
        boost::asio::io_context io_context;
        udp::endpoint endpoint(boost::asio::ip::address_v4::any(),9000);
        udp::socket socket(io_context,endpoint);
        std::cout << "Server, " << socket.local_endpoint().address().to_string()
                  << ":" << socket.local_endpoint().port() << " started at this adress" << std::endl;
        while(true) 
        {
            char data[1024];
            udp::endpoint sender_endpoint;
            size_t length = socket.receive_from(boost::asio::buffer(data,1024),sender_endpoint);
            std::string received_data(data,length);
            std::cout<<"received data: "<<received_data<<"\n";
            if(received_data == "quit\n" || received_data == "quit") 
            {
                socket.close();
                break;
            }
            std::string reply = "veri alindi\n";
            socket.send_to(boost::asio::buffer(reply),sender_endpoint);
        }
    }
    catch(std::exception& e) 
    {
        std::cerr<<e.what() << "\n";
    }
    return 0;
}
