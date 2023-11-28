void sortOrdersBubble(std::queue<Order>& orders) {
    std::vector<Order> ordersVector;
    while (!orders.empty()) {
        ordersVector.push_back(orders.front());
        orders.pop();
    }

    // Bubble sort
    for (size_t i = 0; i < ordersVector.size() - 1; ++i) {
        for (size_t j = 0; j < ordersVector.size() - i - 1; ++j) {
            if (ordersVector[j].amount > ordersVector[j + 1].amount) {
                // Swap if out of order
                std::swap(ordersVector[j], ordersVector[j + 1]);
            }
        }
    }

    // Convert the vector back to a queue
    for (const auto& order : ordersVector) {
        orders.push(order);
    }
}

bool searchOrder(const std::queue<Order>& orders, const std::string& targetCode, Order& foundOrder) {
    std::queue<Order> tempQueue = orders; // Create a copy to avoid modifying the original queue

    while (!tempQueue.empty()) {
        if (tempQueue.front().code == targetCode) {
            foundOrder = tempQueue.front();
            return true; // Order found
        }
        tempQueue.pop();
    }

    return false; // Order not found
}