#ifndef CHANNEL_H
#define CHANNEL_H

typedef enum {
    PUBLIC,
    PRIVATE
} ChannelType;

typedef struct {
    char* name;
    ChannelType type;
} Channel;

Channel* create_channel(const char* name, ChannelType type);
void delete_channel(Channel* channel);

#endif