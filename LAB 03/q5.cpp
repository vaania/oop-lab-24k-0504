#include <iostream>

using namespace std;

class MusicPlayer
{
private:
    string playlist[10];
    int songCount;
    string currentSong;

public:
    MusicPlayer()
    {
        songCount = 0;
        currentSong = "";
    }

    void setSong(string song)
    {
        if (songCount < 10)
        {
            playlist[songCount] = song;
            songCount++;
            cout << "Song added: " << song << endl;
        }
        else
        {
            cout << "Playlist is full!\n";
        }
    }

    void removeSong(string song)
    {
        for (int i = 0; i < songCount; i++)
        {
            if (playlist[i] == song)
            {
                for (int j = i; j < songCount - 1; j++)
                {
                    playlist[j] = playlist[j + 1];
                }
                songCount--;
                cout << "Song removed: " << song << endl;
                return;
            }
        }
        cout << "Song not found!\n";
    }

    void setCurrentlyPlaying(string song)
    {
        for (int i = 0; i < songCount; i++)
        {
            if (playlist[i] == song)
            {
                currentSong = song;
                cout << "Now playing: " << song << endl;
                return;
            }
        }
        cout << "Song not found in playlist!\n";
    }

    void displayPlaylist()
    {
        cout << "Playlist:\n";
        for (int i = 0; i < songCount; i++)
        {
            cout << i + 1 << ". " << playlist[i] << endl;
        }
    }

    string getCurrentlyPlaying()
    {
        return currentSong.empty() ? "No song is playing" : currentSong;
    }
};

int main()
{
    MusicPlayer player;

    player.setSong("BitterSweet");
    player.setSong("Slowdown");
    player.setSong("Let it go");

    player.displayPlaylist();

    player.setCurrentlyPlaying("Slowdown");

    player.removeSong("BitterSweet");

    player.displayPlaylist();

    cout << "Currently Playing: " << player.getCurrentlyPlaying() << endl;

    return 0;
}
