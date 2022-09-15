#pragma once
#include <vector>

#include "BasicConnection.hpp"
#include "Channel.hpp"
#include "ERR_RPL.hpp"

class Channel;

class User : public TCP::BasicConnection {
    public:

        User(TCP::TCPSocket *socket);
        virtual ~User();

        const std::string       &nickname() const;
        void					setNickname(const std::string &nickname);

        const std::string       &username() const;
        void					setUsername(const std::string &username);

        const std::string       &realname() const;
        void					setRealname(const std::string &realname);

        int                     state() const;
        void					setState(int state);

        bool                    isRegistered() const;

        std::string             getPrefix() const;

        std::string             getResponse(User &u, int code, std::vector<std::string> args);
        int                     reply(User &u, int code, std::vector<std::string> args);
        void                    welcome(User &u);

        Channel                 *getChannel() const;
        void                    joinChannel(User &u, Channel *channel);
	    void                    setChannel(Channel *channel);

    private:
        Channel                 *_channel;
        std::string             _nickname;
        std::string             _username;
        std::string             _realname;
        bool                    _registered;
        int                     _state;

    protected:
        time_t                  _idle;
};