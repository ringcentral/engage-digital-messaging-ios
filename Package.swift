// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Dimelo",
    platforms: [
        .iOS(.v11),
    ],
    products: [
        .library(
            name: "Dimelo",
            targets: ["Dimelo"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(name: "Dimelo", path: "./Dimelo.xcframework"),
    ]
)
