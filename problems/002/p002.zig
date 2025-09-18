const std = @import("std");

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();

    const result: u32 = resolve(4000000);

    try stdout.print("Result={d}\n", .{result});
}

pub fn resolve(max: u32) u32 {
    var x: u32 = 1;
    var y: u32 = 2;
    var sum: u32 = y;

    while (y < max) {
        const x1: u32 = y;
        const y2: u32 = x + y;

        if (y2 % 2 == 0) {
            sum += y2;
        }

        x = x1;
        y = y2;
    }

    return sum;
}
