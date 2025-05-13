const std = @import("std");

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();

    const example_result: u32 = example();

    try stdout.print("Example={d}\n", .{example_result});

    const problem_result: u32 = problem();

    try stdout.print("Result={d}\n", .{problem_result});
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

pub fn example() u32 {
    return resolve(3, 5, 10);
}

pub fn problem() u32 {
    return resolve(3, 5, 1000);
}
