#pragma once

namespace trrne {
	class Teleporter {
	private:
		const s3d::Vec2 NoData = s3d::Vec2(16e2, 16e2);
		s3d::Vec2* targetPtr;

	public:
		Teleporter(s3d::Vec2* target)
			:targetPtr(target)
		{ }

		void teleport(s3d::Vec2 $to) {
			if (targetPtr == nullptr) {
				throw std::exception("nullptr");
			}
			*targetPtr = $to;
		}

		static void teleport(s3d::Vec2& target, const s3d::Vec2 to) noexcept {
			target = to;
		}
	};
}
