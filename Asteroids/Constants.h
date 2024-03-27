#pragma once


// I have put constants separately, it is for better organization and now they are easier to edit.
struct Constants {
	static constexpr int windowWidth{ 1000 };
	static constexpr int windowHeight{ 800 };
	static constexpr float meteorSpeed{ 6.0f };
	static constexpr float playerWidth{ 60.0f };
	static constexpr float playerSpeed{ 8.0f };
	static constexpr float meteorWidth{ 25.0f };
	static constexpr float meteorHeight{ 25.0f };
	static constexpr float meteorStrength{ 3.0f };
	static constexpr float playersHealth{ 1000.f };
	static constexpr float playersSlowestSpeed{ 0.5f };
	static constexpr float slowRatio{ 0.95f };
	static constexpr float playerRotationSpeed{ 3.0f };
	static constexpr float bulletSpeed { 1.0f };
};