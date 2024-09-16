function parsePath(path) {
    const parts = path.match(PATH)[1];
    return parts.split(' > ').map(p => {
        const vector = p.match(VECTOR);
        if (vector) {
            return {
                type: 'Vector',
                x: parseInt(vector[1], 10),
                y: parseInt(vector[2], 10)
            };
        } else {
            const bezier = p.match(BEZIER_CURVE);
            return {
                type: 'BezierCurve',
                x0: parseInt(bezier[1], 10),
                y0: parseInt(bezier[2], 10),
                x1: parseInt(bezier[3], 10),
                y1: parseInt(bezier[4], 10),
                cx0: parseInt(bezier[5], 10),
                cy0: parseInt(bezier[6], 10),
                cx1: parseInt(bezier[7], 10),
                cy1: parseInt(bezier[8], 10)
            };
        }
    });
}
