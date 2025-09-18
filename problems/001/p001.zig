const std = @import("std");

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();

    const result: u32 = resolve(3, 5, 1000);

    try stdout.print("Result={d}\n", .{result});
}

pub fn resolve(n1: u32, n2: u32, max: u32) u32 {
    var sum: u32 = 0;
    for (1..max) |i| {
        if (i % n1 == 0) {
            sum = sum + @as(u32, @intCast(i));
        } else if (i % n2 == 0) {
            sum = sum + @as(u32, @intCast(i));
        }
    }
    return sum;
}
