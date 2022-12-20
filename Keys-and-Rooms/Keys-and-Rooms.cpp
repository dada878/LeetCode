class Solution {
public:
    void visitRoom(vector&lt;int&gt;&amp; keys, vector&lt;int&gt; room) {
        for (int i = 0; i &lt; room.size(); i++) {
            keys.push_back(room[i]);
        }
    }
    bool canVisitAllRooms(vector&lt;vector&lt;int&gt;&gt;&amp; rooms) {
        vector&lt;int&gt; keys;
        vector&lt;bool&gt; visited(rooms.size());
        visitRoom(keys, rooms[0]);
        visited[0] = true;
        while (keys.size() &gt; 0) {
            for (int i = 0; i &lt; keys.size(); i++) {
                visitRoom(keys, rooms[keys[i]]);
                rooms[keys[i]].clear();
                visited[keys[i]] = true;
                keys.erase(keys.begin() + i);
            }
        }
        for (int i = 0; i &lt; visited.size(); i++) {
            if (visited[i] == false) return false;
        }
        return true;
    }
};