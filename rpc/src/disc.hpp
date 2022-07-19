#include "discord-rpc/include/discord_rpc.h"
#include <time.h>

static int64_t startTime;
char const* APPLICATION_ID = "704721375050334300";

void discordInit() {
    startTime = time(NULL);
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
    Discord_Initialize(APPLICATION_ID, &handlers, 1, NULL);
}

void updateDiscordPresence(char const* state, char const* details, char const* smallImage, char const* smallText) {
        DiscordRichPresence discordPresence;
        memset(&discordPresence, 0, sizeof(discordPresence));
        discordPresence.state = state;
        discordPresence.details = details;
        discordPresence.startTimestamp = startTime;
        discordPresence.largeImageKey = "gd";
        discordPresence.smallImageKey = smallImage;
        discordPresence.smallImageText = smallText;
        Discord_UpdatePresence(&discordPresence);
}
