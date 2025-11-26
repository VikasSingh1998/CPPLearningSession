Real World Example
------------------
🏭 1. Logging System (Enterprise Software)
Scenario:
Multiple parts of a large application (e.g., banking software) call a centralized logging function. 
Sometimes, that logging function itself calls another function that also logs something.
 
Problem:
If both functions try to lock the same mutex, it causes a deadlock.
Solution:
Use std::recursive_mutex so that the same thread can lock multiple times safely.

std::recursive_mutex log_mutex;
void log_debug(const std::string& msg) {
    std::lock_guard<std::recursive_mutex> lock(log_mutex);
    std::cout << "[DEBUG] " << msg << std::endl;
}

void log_transaction(const std::string& txn) {
    std::lock_guard<std::recursive_mutex> lock(log_mutex);
    log_debug("Transaction started");
    std::cout << "Processing: " << txn << std::endl;
    log_debug("Transaction ended");
}
===========================================================================================
===========================================================================================
🎮 2. Game Engine – Scene Graph Traversal
Scenario:
Game engines (like Unreal or Unity) use scene graphs — tree-like structures where each node represents an object. Updating or rendering the scene may involve recursive traversal.
Problem:
Each node update may need to lock shared resources (e.g., physics engine, renderer). Recursive traversal + locking = deadlock risk.
Solution:
Use recursive_mutex to allow safe recursive locking during traversal.

std::recursive_mutex scene_mutex;

void update_node(Node* node) {
    std::lock_guard<std::recursive_mutex> lock(scene_mutex);
    node->update();
    for (auto child : node->children) {
        update_node(child); // recursive call
    }
}
==============================================================================================





