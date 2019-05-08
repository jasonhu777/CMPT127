
int InRectangle(float p[2], float rect[4]) {


	float pointX = p[0];
	float pointY = p[1];

	float x1Rect = rect[0];
	float y1Rect = rect[1];
	float x2Rect = rect[2];
	float y2Rect = rect[3];

	if (pointX >= x1Rect && pointX <= x2Rect) {
		if ((pointY >= y1Rect && pointY <= y2Rect) ||
			(pointY <= y1Rect && pointY >= y2Rect)) {
			return 1;		
			} 
	}
		
	
	if (pointX >= x2Rect && pointX <= x1Rect) {
		if ((pointY >= y2Rect && pointY <= y1Rect) ||
			(pointY <= y1Rect && pointY >= y2Rect)) {
		return 1;
		}
	}

	if (pointX <= x1Rect && pointX >= x2Rect) {
		if ((pointY >= y1Rect && pointY <= y2Rect) ||
			(pointY <= y1Rect && pointY >= y2Rect)) {
			return 1;
		}
	}

	if (pointX <= x2Rect && pointX >= x1Rect) {
		if ((pointY >= y2Rect && pointY <= y1Rect) ||
			(pointY <= y2Rect && pointY >= y1Rect)) {
			return 1;
		}
	}

	if (pointY <= y1Rect && pointY >= y2Rect) {
		if ((pointX <= x1Rect && pointX >= x2Rect) ||
			(pointX >= x1Rect && pointX <= x2Rect)) {
			return 1;
		}
	}

	if (pointY <= y2Rect && pointY >= y1Rect) {
		if ((pointX <= x2Rect && pointX >= x1Rect) ||
			(pointX >= x2Rect && pointX <= x1Rect)) {
			return 1;
		}
	}

	if (pointX >= x1Rect && pointX <= x2Rect) {
		if ((pointY <= y1Rect && pointY >= y2Rect) ||
			(pointY <= y2Rect && pointY >= y1Rect)) {
				return 1;
			}
	}

	if (pointX >= x2Rect && pointX <= x1Rect) {
		if ((pointY <= y2Rect && pointY >= y1Rect) ||
			(pointY <= y1Rect && pointY >= y2Rect)) {
			return 1;
		}
	}
	return 0; 

}