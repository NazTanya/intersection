#include"Vector3D.h"
#include"Segment3D.h"
#include<limits>
#include<iostream>

bool SegmentsOnOneLine()
{
	Vector3D begin, end, ans;
	IntersectionType type;
	
	begin.Set(3, 0, 5);
	end.Set(5, 6, 3);
	Segment3D first_segment(begin, end);
	first_segment.PrintSegment();

	begin.Set(4, 3, 4);
	end.Set(6, 9, 2);
	Segment3D second_segment(begin, end);
	second_segment.PrintSegment();

	type = first_segment.Intersection(second_segment, ans);

	if (type != OnOneLineIntersection){
			return false;
	}

	if (ans == Vector3D(std::numeric_limits<double>::max())){
			return false;
	}
	else {
			std::cout << "Отрезки пересекаются в точке: (" << ans.X << ", " << ans.Y << ", " << ans.Z << ")" << std::endl;
	}

	begin.Set(3, 0, 5);
	end.Set(6, 9, 2);
	first_segment.Set(begin, end);
	first_segment.PrintSegment();

	begin.Set(4, 3, 4);
	end.Set(5, 6, 3);
	second_segment.Set(begin, end);
	second_segment.PrintSegment();

	type = first_segment.Intersection(second_segment, ans);
	if (type != OnOneLineIntersection) {
		return false;
	}

	if (ans == Vector3D(std::numeric_limits<double>::max())) {
		return false;
	}
	else {
		std::cout << "Отрезки пересекаются в точке: (" << ans.X << ", " << ans.Y << ", " << ans.Z << ")" << std::endl;
	}

	begin.Set(5, 6, 3);
	end.Set(6, 9, 2);
	first_segment.Set(begin, end);
	first_segment.PrintSegment();

	begin.Set(3, 0, 5);
	end.Set(4, 3, 4);
	second_segment.Set(begin, end);
	second_segment.PrintSegment();

	type = first_segment.Intersection(second_segment, ans);
	if (type != OnOneLineNoIntersection) {
		return false;
	}

	if (!(ans == Vector3D(std::numeric_limits<double>::max()))) {
		return false;
	}
	else {
		std::cout << "Отрезки не пересекаются" << std::endl;
	}

	begin.Set(3, 0, 5);
	end.Set(4, 3, 4);
	first_segment.Set(begin, end);
	first_segment.PrintSegment();

	begin.Set(5, 6, 3);
	end.Set(6, 9, 2);
	second_segment.Set(begin, end);
	second_segment.PrintSegment();

	type = first_segment.Intersection(second_segment, ans);
	if (type != OnOneLineNoIntersection) {
		return false;
	}

	if (!(ans == Vector3D(std::numeric_limits<double>::max()))) {
		return false;
	}
	else {
		std::cout << "Отрезки не пересекаются" << std::endl;
	}

	begin.Set(4, 3, 4);
	end.Set(6, 9, 2);
	first_segment.Set(begin, end);
	first_segment.PrintSegment();


	begin.Set(3, 0, 5);
	end.Set(5, 6, 3);
	second_segment.Set(begin, end);
	second_segment.PrintSegment();

	type = first_segment.Intersection(second_segment, ans);
	if (type != OnOneLineIntersection) {
		return false;
	}

	if (ans == Vector3D(std::numeric_limits<double>::max())) {
		return false;
	}
	else {
		std::cout << "Отрезки пересекаются в точке: (" << ans.X << ", " << ans.Y << ", " << ans.Z << ")" << std::endl;
	}

	return true;
}

void main() {

	setlocale(LC_ALL, "RUS");


	SegmentsOnOneLine();

	Vector3D begin(3, 0, 5), ans;
	Vector3D end(6, 9, 2);
	IntersectionType type;
	Segment3D first_segment(begin, end);
	first_segment.PrintSegment();

	begin.Set(3, 0 ,7);
	end.Set(6, 9, 1);
	Segment3D second_segment(begin, end);
	second_segment.PrintSegment();

	type = first_segment.Intersection(second_segment, ans);

	if (type == HasIntersection) {
		std::cout << "Отрезки пересекаются в точке: (" << ans.X << ", " << ans.Y << ", " << ans.Z << ")" << std::endl;
	}
	else {
		std::cout << "Ошибка" << std::endl;
	}

	//точки не принадлежат одной плоскости
	first_segment.PrintSegment();
	begin.Set(3, 0, 7);
	end.Set(7, 15, 3);
	second_segment.Set(begin, end);
	second_segment.PrintSegment();

	type =  first_segment.Intersection(second_segment, ans);
	if (type == NoIntersection) {
		std::cout << "Отрезки не пересекаются"<< std::endl;
	}
	else {
		std::cout << "Ошибка" << std::endl;
	}
}