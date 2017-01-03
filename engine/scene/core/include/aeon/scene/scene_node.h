/*
 * ROBIN DEGEN; CONFIDENTIAL
 *
 * 2012 - 2017 Robin Degen
 * All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains the property of
 * Robin Degen and its suppliers, if any. The intellectual and technical
 * concepts contained herein are proprietary to Robin Degen and its suppliers
 * and may be covered by U.S. and Foreign Patents, patents in process, and are
 * protected by trade secret or copyright law. Dissemination of this
 * information or reproduction of this material is strictly forbidden unless
 * prior written permission is obtained from Robin Degen.
 */

#pragma once

#include <aeon/scene/scene_object.h>
#include <aeon/scene/exceptions.h>
#include <aeon/scene/movable_object.h>
#include <aeon/utility.h>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <vector>
#include <memory>

namespace aeon
{
namespace scene
{

class scene_node : public std::enable_shared_from_this<scene_node>, public movable_object, public utility::noncopyable
{
    friend class scene_manager;

public:
    /*!
     * Destructor
     */
    virtual ~scene_node() = default;

    /*!
     * Create a new scene node attached to this scene node.
     */
    auto create_child_scene_node() -> std::shared_ptr<scene_node>;

    /*!
     * Attach a scene node to this node. This will automatically detach the given node from it's current parent,
     * if any.
     */
    void attach_child(const std::shared_ptr<scene_node> &node);

    /*!
     * Detach a scene node. The given scene node will have it's parent set to nullptr.
     * Will result in undefined (dangerous!) behavior if the given scene node was not a child of
     * this node.
     */
    void detach_child(const std::shared_ptr<scene_node> &node);

    /*!
     * Detach all children scene_nodes that were attached to this one.
     */
    void detach_all_children();

    /*!
     * Attach an object to this scene node.
     * TODO: Can the same object be attached to multiple scene nodes? What are the implications of this?
     */
    void attach_scene_object(const std::shared_ptr<scene_object> &object);

    /*!
     * Detach an object from this scene node.
     */
    void detach_scene_object(const std::shared_ptr<scene_object> &object);

    /*!
     * Detach all objects from this scene node.
     */
    void detach_all_scene_objects();

    /*!
     * Recalculate the total matrix of this scenenode if either this or the parent node is marked as dirty. If neither
     * is marked as dirty, no recalculation is done. This also triggers a call to recalculate_matrices for each of the
     * children.
     */
    void recalculate_matrices();

    /*!
     * Get the calculated matrix, which are all the matrix multiplications of everything up until the root node.
     * If this node is flagged is dirty (see: is_dirty()), this value may be incorrect. Use recalculate_matrices() if
     * you want to be sure of a correct value;
     */
    const auto &get_total_matrix() const
    {
        return total_matrix_;
    }

    /*!
     * Get the center point of this scene node.
     * If this node is flagged is dirty (see: is_dirty()), this value may be incorrect. Use recalculate_matrices() if
     * you want to be sure of a correct value;
     */
    auto get_center_point() const
    {
        return total_matrix_ * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    }

    /*!
     * Get the parent this scene node is attached to. Equals nullptr if this node isn't attached to anything.
     */
    auto get_parent() const
    {
        return parent_;
    }

    /*!
     * Recursively detach and cleanup all scene nodes and their children from this node.
     */
    void cleanup_children();

    /*!
     * Make a deepcopy of this scene node and all it's children so that it can be attached somewhere else.
     */
    auto clone() -> std::shared_ptr<scene_node>;

    /*!
     * Get a vector of references to all children.
     */
    std::vector<std::reference_wrapper<scene_node>> get_children_refs() const;

    /*!
     * Get all attached objects to this node
     */
    const auto &get_scene_objects() const
    {
        return scene_objects_;
    }

private:
    /*!
     * Construtor
     * A scene node is marked as dirty by default.
     */
    scene_node();

    /*!
     * The scene node that this node is attached to, or nullptr if not attached to anything.
     */
    std::shared_ptr<scene_node> parent_;

    /*!
     * All attached scene nodes.
     */
    std::vector<std::shared_ptr<scene_node>> children_;

    /*!
     * All attached render objects
     */
    std::vector<std::shared_ptr<scene_object>> scene_objects_;

    /*!
     * The precalculated matrix multiplications of everything up until the root node.
     */
    glm::mat4 parent_matrix_;

    /*!
     * The calculated matrix for this node (matrix_ * parent_matrix_)
     */
    glm::mat4 total_matrix_;

    /*!
     * True if this is the root node
     */
    bool is_root_;
};

} // namespace scene
} // namespace aeon
