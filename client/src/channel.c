#include "channel.h"
#include <stdlib.h>
#include <string.h>

Channel* create_channel(const char* name, ChannelType type) {
    Channel* channel = (Channel*)malloc(sizeof(Channel));
    if (channel) {
        channel->name = strdup(name);
        channel->type = type;
    }
    return channel;
}

void delete_channel(Channel* channel) {
    if (channel) {
        free(channel->name);
        free(channel);
    }
}